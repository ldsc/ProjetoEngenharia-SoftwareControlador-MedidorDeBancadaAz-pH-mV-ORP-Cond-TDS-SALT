class  Gnuplot
{ public:
  static void   Terminal (const std::string & type);
  //---------------------------------------------------------------------------------Construtores
  /// @brief Construtor, seta o estilo do grafico na construcao.
  Gnuplot (const std::string & style = "points");
  /// @brief Construtor, plota um grafico a partir dde um vector, diretamente na construcao.
  Gnuplot (const std::vector < double >&x,const std::string & title = "",const std::string & style = "points",
	   const std::string & labelx = "x",const std::string & labely = "y");
  /// @brief Construtor, plota um grafico do tipo x_y a partir de vetores, diretamente na construcao.
  Gnuplot (const std::vector < double >&x,const std::vector < double >&y,const std::string & title = "",
	   const std::string & style = "points",const std::string & labelx = "x",const std::string & labely = "y");
  /// @brief Construtor, plota um grafico de x_y_z a partir de vetores, diretamente na construcao.
  Gnuplot (const std::vector < double >&x,const std::vector < double >&y,const std::vector < double >&z,
	   const std::string & title = "",const std::string & style = "points",const std::string & labelx = "x",
	   const std::string & labely = "y",const std::string & labelz = "z");
  /// @brief Destrutor, necessario para deletar arquivos temporarios.
  ~Gnuplot ();
  //--------------------------------------------------------------------------------------------
  /// @brief Envia comando para o gnuplot.
  Gnuplot & cmd (const std::string & cmdstr);
  /// @brief Sobrecarga operador <<, funciona como Comando.
  Gnuplot & operator<< (const std::string & cmdstr);
  /// @brief  Seta estilos de linhas (em alguns casos sao necessarias informacoes adicionais).
  /// lines, points, linespoints, impulses, dots, steps, fsteps, histeps,
  /// boxes, histograms, filledcurves
  Gnuplot & Style (const std::string & stylestr = "points");
  /// @brief  Ativa suavizacao. Argumentos para interpolacoes e aproximacoes.
  /// csplines, bezier, acsplines (para dados com valor > 0), sbezier, unique, 
  /// frequency (funciona somente com plot_x, plot_xy, plotfile_x, 
  Gnuplot & Smooth (const std::string & stylestr = "csplines");
  /// @brief Escala o tamanho do ponto usado na plotagem.
  Gnuplot & PointSize (const double pointsize = 1.0);
  /// @brief Ativa/Desativa o grid (padrao = desativado).
  Gnuplot & Grid (bool _fgrid = 1);
  /// @brief Seta taxa de amostragem das funcoes, ou dos dados de interpolacao.
  Gnuplot & Samples (const int samples = 100);
  /// @brief Seta densidade de isolinhas para plotagem de funcoes como superficies (para plotagen 3d).
  Gnuplot & IsoSamples (const int isolines = 10);
  /// @brief Ativa/Desativa remocao de linhas ocultas na plotagem de superficies (para plotagen 3d).
  Gnuplot & Hidden3d (bool _fhidden3d = 1);
  /// @brief Ativa/Desativa desenho do contorno em superficies (para plotagen 3d).
  /// @param base, surface, both.
  Gnuplot & Contour (const std::string & position = "base");
  /// @brief  Ativa/Desativa a visualizacao da superficie (para plotagen 3d).
  Gnuplot & Surface (int _fsurface = 1);  /// @brief Ativa/Desativa a legenda (a legenda é setada por padrao).
  Gnuplot & Legend (const std::string & position = "default");
  /// @brief Ativa/Desativa a legenda (a legenda é setada por padrao).
  Gnuplot & Legend (int _flegend);
  /// @brief Ativa/Desativa o titulo da secao do gnuplot.
  Gnuplot & Title (const std::string & title = "");  /// @brief Seta o rotulo (nome) do eixo y.
  Gnuplot & YLabel (const std::string & label = "y");  /// @brief Seta o rotulo (nome) do eixo x.
  Gnuplot & XLabel (const std::string & label = "x");
  /// @brief Seta o rotulo (nome) do eixo z.
  Gnuplot & ZLabel (const std::string & label = "z");
  /// @brief Seta intervalo do eixo x.
  Gnuplot & XRange (const int iFrom, const int iTo);
  /// @brief Seta intervalo do eixo y.
  Gnuplot & YRange (const int iFrom, const int iTo);  /// @brief Seta intervalo do eixo z.
  Gnuplot & ZRange (const int iFrom, const int iTo);
  /// @brief Seta escalonamento automatico do eixo x (default).
  Gnuplot & XAutoscale ();
  /// @brief Seta escalonamento automatico do eixo y (default).
  Gnuplot & YAutoscale ();
  /// @brief Seta escalonamento automatico do eixo z (default).
  Gnuplot & ZAutoscale ();
  /// @brief Ativa escala logaritma do eixo x (logscale nao e setado por default).
  Gnuplot & XLogscale (const double base = 10);
  /// @brief Ativa/Desativa escala logaritma do eixo x (logscale nao e setado por default).
  Gnuplot & XLogscale (bool _fxlogscale);  /// @brief Ativa escala logaritma do eixo y (logscale nao e setado por default).
  Gnuplot & YLogscale (const double base = 10);
  /// @brief Ativa/Desativa escala logaritma do eixo y (logscale nao e setado por default).
  Gnuplot & YLogscale (bool _fylogscale);  /// @brief Ativa escala logaritma do eixo y (logscale nao e setado por default).
  Gnuplot & ZLogscale (const double base = 10);  /// @brief Ativa/Desativa escala logaritma do eixo y (logscale nao e setado por default).
  Gnuplot & ZLogscale (bool _fzlogscale);
  /// @brief Seta intervalo da palette (autoscale por padrao).
  Gnuplot & CBRange (const int iFrom, const int iTo);
  //----------------------------------------------------------------------------------
  /// @brief Plota dados de um arquivo de disco.
  /// @brief Plota dados de um arquivo de disco.
  Gnuplot & PlotFile (const std::string & filename,const int column = 1, const std::string & title = "");
    /// @brief Plota dados de um vector.
  Gnuplot & PlotVector (const std::vector < double >&x,const std::string & title = "");
  /// @brief Plota pares x,y a partir de um arquivo de disco.
  Gnuplot & PlotFile (const std::string & filename, const int column_x = 1,
		      const int column_y = 2, const std::string & title = "");
  /// @brief Plota pares x,y a partir de vetores.
  Gnuplot & PlotVector (const std::vector < double >&x, const std::vector < double >&y,
			const std::string & title = "");
  /// @brief Plota pares x,y com barra de erro dy a partir de um arquivo.
  Gnuplot & plotfile_xy_err (const std::string & filename,
			     const int column_x = 1, const int column_y = 2,
			     const int column_dy =3, const std::string & title = "");
  /// @brief Plota pares x,y com barra de erro dy a partir de um arquivo.
  Gnuplot & PlotFileXYErrorBar (const std::string & filename,
				const int column_x = 1, const int column_y = 2,
				const int column_dy = 3, const std::string & title = "");
  /// @brief Plota pares x,y com barra de erro dy a partir de vetores.
  Gnuplot & PlotVectorXYErrorBar (const std::vector < double >&x, const std::vector < double >&y,
				  const std::vector < double >&dy, const std::string & title = "");
  /// @brief  Plota valores de x,y,z a partir de um arquivo de disco.
  Gnuplot & PlotFile (const std::string & filename, const int column_x = 1,
		      const int column_y = 2,const int column_z = 3, const std::string & title = "");
  /// @brief  Plota valores de x,y,z a partir de vetores.
  Gnuplot & PlotVector (const std::vector < double >&x,const std::vector < double >&y,
			const std::vector < double >&z,const std::string & title = "");
  /// @brief Plota uma equacao da forma y = ax + b, voce fornece os coeficientes a e b.
  Gnuplot & PlotSlope (const double a, const double b,const std::string & title = "");
  /// @brief Plota uma  equacao fornecida como uma std::string y=f(x).
  /// Escrever somente a funcao f(x) e nao y= ;   /// A variavel independente deve ser x.
  /// Exemplo: gnuplot->PlotEquation(CFuncao& obj); 
  Gnuplot & PlotEquation (const std::string & equation,const std::string & title = "");
  /// @brief Plota uma equacao fornecida na forma de uma std::string z=f(x,y).
  /// Escrever somente a funcao f(x,y) e nao z=, as vaiaveis independentes sao x e y.
  // gnuplot->PlotEquation3d(CPolinomio());
  Gnuplot & PlotEquation3d (const std::string & equation,const std::string & title = "");
  /// @brief Plota uma imagem.
  Gnuplot & PlotImage (const unsigned char *ucPicBuf,const int iWidth, const int iHeight,
		       const std::string & title = "");
  //----------------------------------------------------------------------------------
  // Repete o ultimo comando de plotagem, seja plot (2D) ou splot (3D)
  // Usado para visualizar plotagens, após mudar algumas opcoes de plotagem
  // ou quando gerando o mesmo grafico para diferentes dispositivos (showonscreen, savetops)
  Gnuplot & Replot ();
  // Reseta uma sessao do gnuplot (próxima plotagem apaga definicoes previas)
  Gnuplot & Reset ();  // Reseta uma sessao do gnuplot e seta todas as variaveis para o default
  Gnuplot & ResetAll ();
  // Verifica se a sessao esta valida
  bool  is_valid ();
  // Verifica se a sessao esta valida
  bool  IsValid ();
};
typedef Gnuplot   CGnuplot;
#endif
