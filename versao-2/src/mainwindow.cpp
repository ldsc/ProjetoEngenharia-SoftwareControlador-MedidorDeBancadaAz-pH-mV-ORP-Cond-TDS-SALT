#include "mainwindow.h"
#include "sensor.cpp"
#include "ui_mainwindow.h"

#include <Qfile>
#include "measure.h"
#include "enums.h"
#include <ctime>
#include <fstream>
#include <string>
#include <string.h>
#include <QFileDialog>
#include <QMessageBox>
#include <limits.h>
#include "utils.h"

// Setando a funcionalidade de cada botão, caixa de texto, janela...

using namespace std;

/* -------------------------------------------------------------------------- */
/*                    MAIN WINDOW CONSTRUCTOR & DESTRUCTOR                    */
/* -------------------------------------------------------------------------- */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setup refresh loop
    timerEventId = startTimer(1000);
    ui->sb_refresh_rate->setValue(1000);

    // Configurando Grafico da medicao do Analyzer
    ui->gp_analyzer_value->addGraph();
    ui->gp_analyzer_value->graph(0)->setPen(QPen(QColor(40, 110, 255)));
    ui->gp_analyzer_value->xAxis->setLabel("Tempo (ms)");
    ui->gp_analyzer_value->yAxis->setLabel("Medição");
    ui->gp_analyzer_value->legend->setVisible(true);
    ui->gp_analyzer_value->graph()->setName("Medição");

    // Configurando grafico da temperatura  do Analyzer
    ui->gp_analyzer_temp->addGraph();
    ui->gp_analyzer_temp->graph(0)->setPen(QPen(QColor(255, 110, 40)));
    ui->gp_analyzer_temp->xAxis->setLabel("Tempo (ms)");
    ui->gp_analyzer_temp->yAxis->setLabel("Temperatura (ºC)");
    ui->gp_analyzer_temp->legend->setVisible(true);
    ui->gp_analyzer_temp->graph()->setName("Temperatura (ºC)");

    // Configurando Grafico da medicao do Monitor Avancado
    ui->gp_advanced_value->addGraph();
    ui->gp_advanced_value->graph(0)->setPen(QPen(QColor(40, 110, 255)));
    ui->gp_advanced_value->xAxis->setLabel("Tempo (ms)");
    ui->gp_advanced_value->yAxis->setLabel("Medição");
    ui->gp_advanced_value->legend->setVisible(true);
    ui->gp_advanced_value->graph()->setName("Medição");
    ui->gp_advanced_value->setInteraction(QCP::iRangeDrag, true);

    // Configurando grafico da temperatura do Monitor Avancado
    ui->gp_advanced_temp->addGraph();
    ui->gp_advanced_temp->graph(0)->setPen(QPen(QColor(255, 110, 40)));
    ui->gp_advanced_temp->xAxis->setLabel("Tempo (ms)");
    ui->gp_advanced_temp->yAxis->setLabel("Temperatura (ºC)");
    ui->gp_advanced_temp->legend->setVisible(true);
    ui->gp_advanced_temp->graph()->setName("Temperatura (ºC)");
    ui->gp_advanced_temp->setInteraction(QCP::iRangeDrag, true);
}

MainWindow::~MainWindow()
{
    // Kill refresh loop
    killTimer(timerEventId);
    delete ui;
}

/* -------------------------------------------------------------------------- */
/*                          MAIN WINDOW REFRESH LOOP                          */
/* -------------------------------------------------------------------------- */
void MainWindow::timerEvent(QTimerEvent *event)
{
    if( sensor == nullptr ||
        measure_mode == EMeasureMode::EMeasureMode_Unknown ||
        measure_unit == EMeasureUnit::EMeasureUnit_Unknown
    ) 
    {
        return;
    }

    auto measure = sensor->GetMeasure(measure_mode, measure_unit);
    auto refreshRate = ui->sb_refresh_rate->value();

    ui->gp_advanced_value->graph(0)->addData(timerEventCounter * refreshRate, measure->GetValue());
    // Temp LCD
    if(ui->chb_fixed_temp->isChecked())
    {
        ui->gp_advanced_temp->graph(0)->addData(timerEventCounter * refreshRate, ui->ds_temp->value());
    }
    else
    {
        ui->gp_advanced_temp->graph(0)->addData(timerEventCounter * refreshRate, measure->GetTemperature());
    }

    // Recording section
    if(rec && record != nullptr)
    {
        if(ui->chb_fixed_temp->isChecked())
        {
            auto fixed_measure = new Measure(measure->GetMode(), measure->GetUnit(), measure->GetValue(), ui->ds_temp->value());
            record->append(fixed_measure);
        }
        else
        {
            record->append(measure);
        }
    }

    // LCD Section
    if(!hold) {

        // Measure Value LCD
        ui->lcd_value->display(measure->GetValue());

        // Temp LCD
        if(ui->chb_fixed_temp->isChecked())
        {
            ui->lcd_temp->display(ui->ds_temp->value());
        }
        else
        {
            ui->lcd_temp->display(measure->GetTemperature());
        }

        // Update Chart
        ui->gp_advanced_temp->rescaleAxes(true);
        ui->gp_advanced_value->rescaleAxes(true);
        ui->gp_advanced_value->xAxis->setRange(timerEventCounter * refreshRate, 20 * refreshRate, Qt::AlignRight);
        ui->gp_advanced_temp->xAxis->setRange(timerEventCounter * refreshRate, 20 * refreshRate, Qt::AlignRight);
        ui->gp_advanced_temp->replot();
        ui->gp_advanced_value->replot();

    }

    timerEventCounter++;
}

/* -------------------------------------------------------------------------- */
/*                             MAIN WINDOW EVENTS                             */
/* -------------------------------------------------------------------------- */

void MainWindow::on_cb_mode_currentTextChanged(const QString &arg1)
{
    ui->cb_unit->clear();
    ui->cb_unit->setEnabled(true);
    ui->chb_fixed_temp->setEnabled(true);
    ui->chb_fixed_temp->setChecked(false);

    if(arg1.compare(ToString(EMeasureMode::EMeasureMode_Unknown)) == 0)
    {
        ui->cb_unit->setEnabled(false);
        ui->cb_unit->addItem(ToString(EMeasureUnit_Unknown));
        measure_mode = EMeasureMode::EMeasureMode_Unknown;
    }
    else if (arg1.compare(ToString(EMeasureMode::EMeasureMode_pH)) == 0)
    {
        measure_mode = EMeasureMode::EMeasureMode_pH;
        ui->cb_unit->addItem(ToString(EMeasureUnit_pH));

        ui->ds_temp->setValue(25.00);
    }
    else if (arg1.compare(ToString(EMeasureMode::EMeasureMode_mV)) == 0)
    {
        measure_mode = EMeasureMode::EMeasureMode_mV;
        ui->cb_unit->addItem(ToString(EMeasureUnit_mV));
    }
    else if (arg1.compare(ToString(EMeasureMode::EMeasureMode_ORP)) == 0)
    {
        measure_mode = EMeasureMode::EMeasureMode_ORP;
        ui->cb_unit->addItem(ToString(EMeasureUnit_mV));

        ui->chb_fixed_temp->setChecked(true);
        ui->chb_fixed_temp->setEnabled(false);
        ui->ds_temp->setValue(25);
    }
    else if (arg1.compare(ToString(EMeasureMode::EMeasureMode_Conductivity)) == 0)
    {
        measure_mode = EMeasureMode::EMeasureMode_Conductivity;
        ui->cb_unit->addItem(ToString(EMeasureUnit_us));
    }
    else if (arg1.compare(ToString(EMeasureMode::EMeasureMode_TDS)) == 0)
    {
        measure_mode = EMeasureMode::EMeasureMode_TDS;
        ui->cb_unit->addItem(ToString(EMeasureUnit_ppm));

        ui->ds_temp->setValue(25);
    }
    else if (arg1.compare(ToString(EMeasureMode::EMeasureMode_Salinity)) == 0)
    {
        measure_mode = EMeasureMode::EMeasureMode_Salinity;
        ui->cb_unit->addItem(ToString(EMeasureUnit_ppt));
    }
}


void MainWindow::on_cb_sensor_currentTextChanged(const QString &arg1)
{
    ui->cb_mode->clear();
    ui->cb_mode->setEnabled(true);
    ui->cb_unit->clear();
    ui->cb_unit->setEnabled(false);

    if(arg1.compare("[SELECIONE UM TIPO DE SENSOR]") == 0)
    {
        sensor = nullptr;
        ui->cb_mode->setEnabled(false);
    }
    else if (arg1.compare(ToString(ESensorType_86501_551)) == 0)
    {
        sensor = new Sensor_86501_551(); // TODO: Colocar sensor correto
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_Unknown));
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_pH));
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_mV));
    }
    else if (arg1.compare(ToString(ESensorType_86502_552)) == 0)
    {
        sensor = new Sensor_86501_551(); // TODO: Colocar sensor correto
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_Unknown));
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_pH));
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_ORP));
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_mV));
    }
    else if (arg1.compare(ToString(ESensorType_86503_553)) == 0)
    {
        sensor = new Sensor_86501_551(); // TODO: Colocar sensor correto
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_Unknown));
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_Conductivity));
    }
    else if (arg1.compare(ToString(ESensorType_86504_554)) == 0)
    {
        sensor = new Sensor_86501_551(); // TODO: Colocar sensor correto
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_Unknown));
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_pH));
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_ORP));
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_Conductivity));
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_mV));
    }
    else if (arg1.compare(ToString(ESensorType_86505_555)) == 0)
    {
        sensor = new Sensor_86501_551(); // TODO: Colocar sensor correto
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_Unknown));
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_pH));
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_ORP));
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_Conductivity));
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_mV));
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_TDS));
        ui->cb_mode->addItem(ToString(EMeasureMode::EMeasureMode_Salinity));
    }
}

void MainWindow::on_sb_refresh_rate_valueChanged(int arg1)
{
    killTimer(timerEventId);
    timerEventId = startTimer(arg1);
}

void MainWindow::on_btn_hold_clicked()
{
    hold = !hold;

    if(hold) {
        ui->gb_config->setEnabled(false);
        ui->btn_hold->setText("Resume 👍");
        ui->btn_hold->setChecked(true);
        return;
    }

    ui->gb_config->setEnabled(true);
    ui->btn_hold->setText("Hold ✋");
    ui->btn_hold->setChecked(false);
}


void MainWindow::on_chb_fixed_temp_stateChanged(int arg1)
{
    if(arg1 == 0)
    {
        ui->ds_temp->setEnabled(false);
    }
    else if(arg1 == 2)
    {
        ui->ds_temp->setEnabled(true);
    }
    else
    {
        throw errno;
    }
}



void MainWindow::on_btn_about_clicked()
{
    About* dialog = new About();
    dialog->show();
}


void MainWindow::on_btn_rec_clicked()
{
    rec = !rec;

    // Setup recording
    if(rec) {

        // Disable Configs and Functions
        if(hold) ui->btn_hold->click();
        ui->gb_config->setEnabled(false);
        ui->btn_hold->setEnabled(false);

        // Setup variables
        record = new QList<IMeasure*>();

        // Edit Button
        ui->btn_rec->setText("Parar gravação ⬛");
        return;
    }

    //TODO: Salvar Gravacao
    if(record != nullptr)
    {
        // Setup
        std::time_t now = std::time(NULL);
        std::tm * ptm = std::localtime(&now);
        auto currentPath = filesystem::current_path();
        auto recPath = currentPath / "records";

        if(!filesystem::exists(recPath))
        {
            filesystem::create_directory(recPath);
        }

        char fileName[32];
        std::strftime(fileName, 32, "%d-%m-%Y-%H-%M-%S.csv", ptm);

        char dateTimeNow[32];
        std::strftime(dateTimeNow, 32, "%d/%m/%Y %H:%M:%S", ptm);

        QFile csvFile(recPath / fileName);

        // Write file
        if(csvFile.open( QIODevice::WriteOnly))
        {
            QTextStream textStream( &csvFile );
            QStringList stringList;

            stringList << "Mode";
            stringList << "Unit";
            stringList << "Value";
            stringList << "Temp";
            stringList << "Time";
            stringList << "Date";

            textStream << stringList.join( ';' )+"\n";

            for( int row = 1; row < record->count(); row++ )
            {
                auto measure = record->value(row);

                stringList.clear();

                // Mode
                stringList << ToString(measure->GetMode());

                // Unit
                stringList << ToString(measure->GetUnit());

                // Value
                stringstream value_stream;
                value_stream.precision(2);
                value_stream << fixed;
                value_stream <<measure->GetValue();
                string value  = value_stream.str();
                stringList << value.c_str();

                // Temperature
                stringstream temp_value;
                temp_value.precision(2);
                temp_value << fixed;
                temp_value << measure->GetTemperature();
                string temp  = temp_value.str();
                stringList << temp.c_str();

                // Time
                auto refreshRate = ui->sb_refresh_rate->value();
                stringList << to_string(row * refreshRate).c_str();

                // Date
                stringList << dateTimeNow;

                // Add next line
                textStream << stringList.join( ';' )+"\n";
            }

            csvFile.close();

            QString message = "Gravação gerada com sucesso!\n";
            message.append("Nome do Arquivo: ");
            message.append(fileName);
            QMessageBox::information(this, "Gravador", message);
        }
    }

    ui->gb_config->setEnabled(true);
    ui->btn_hold->setEnabled(true);
    ui->btn_rec->setText("Gravar 🔴");
    record = nullptr;
}


void MainWindow::on_cb_unit_currentTextChanged(const QString &arg1)
{
    measure_unit = EMeasureUnit_mmHg;
}


void MainWindow::on_btn_inspect_clicked()
{
    auto recordPath = filesystem::current_path() / "records";
    QString filePath = QFileDialog::getOpenFileName(this, "Open a record file", QString::fromStdString(recordPath.string()));
    QFile csvFile(filePath);

    // Write file
    if(csvFile.open( QIODevice::ReadWrite))
    {
        ui->gp_analyzer_temp->graph(0)->data()->clear();
        ui->gp_analyzer_value->graph(0)->data()->clear();

        csvFile.readLine(); // Clear column titles

        int time = 0;
        QList<double>* values = new QList<double>();
        QList<double>* temps = new QList<double>();

        while (!csvFile.atEnd()) {
            QByteArray line = csvFile.readLine();
            auto teste = line.split(';');

            // Modo de Funcionamento
            ui->lb_record_mode->setText(QString::fromStdString(teste[0].toStdString()));

            // Unidade de medida
            ui->lb_record_unit->setText(QString::fromStdString(teste[1].toStdString()));

            // Data da gravacao
            ui->lb_record_date->setText(QString::fromStdString(teste[5].toStdString()));

            // Calculando Tempo
            int t_time = stod(teste[4].toStdString());
            if(t_time > time) time = t_time;

            double value = stod(teste[2].toStdString());
            double temp = stod(teste[3].toStdString());

            values->append(value);
            ui->gp_analyzer_value->graph(0)->addData(t_time, value);
            ui->gp_analyzer_value->graph()->setName(QString::fromStdString(teste[1].toStdString()));

            temps->append(temp);
            ui->gp_analyzer_temp->graph(0)->addData(t_time, temp);

        }

        // Populando Range Medicao
        stringstream value;
        value << Utils::GetMin(values);
        value << " - ";
        value << Utils::GetMax(values);
        ui->lb_record_value_range->setText(QString::fromStdString(value.str()));

        // Populando Range Medicao
        stringstream temp;
        temp << Utils::GetMin(temps);
        temp << " - ";
        temp << Utils::GetMax(temps);
        ui->lb_record_temp_range->setText(QString::fromStdString(temp.str()));

        // Popular contagem de Registros
        stringstream count;
        count << values->count();
        ui->lb_record_count->setText(QString::fromStdString(count.str()));

        // Populando Tempo de Execucao
        stringstream tim;
        tim << time;
        ui->lb_record_time->setText(QString::fromStdString(tim.str()));

        // Refresh rate
        stringstream refresh;
        refresh << time / values->count();
        ui->lb_record_refresh_rate->setText(QString::fromStdString(refresh.str()));

        // Mediana - Media Value
        stringstream medianaValuesString;
        medianaValuesString << Utils::GetMediana(values);
        medianaValuesString << " - ";
        medianaValuesString << Utils::GetMedia(values);
        ui->lb_record_med_value->setText(QString::fromStdString(medianaValuesString.str()));

        // Mediana - Media Temp
        stringstream medianaTempsString;
        medianaTempsString << Utils::GetMediana(temps);
        medianaTempsString << " - ";
        medianaTempsString << Utils::GetMedia(temps);
        ui->lb_record_med_temp->setText(QString::fromStdString(medianaTempsString.str()));

        // Desvio Padrao
        stringstream desvio_value;
        desvio_value << Utils::GetDesvioPadrao(values);
        ui->lb_record_value_dp->setText(QString::fromStdString(desvio_value.str()));

        // Desvio Padrao
        stringstream desvio_temp;
        desvio_temp << Utils::GetDesvioPadrao(temps);
        ui->lb_record_temp_dp->setText(QString::fromStdString(desvio_temp.str()));

        // Plot and Rescale Axes of Temperature graph
        ui->gp_analyzer_temp->rescaleAxes(true);
        ui->gp_analyzer_temp->replot();

        // Plot and Rescale Axes of Value graph
        ui->gp_analyzer_value->rescaleAxes(true);
        ui->gp_analyzer_value->graph()->setName("Medição");
        ui->gp_analyzer_value->replot();

        csvFile.close();
    }
}

