# Etapas para criar seu projeto de engenharia

Um SCV - Sistema de Controle de Versões, permite gerenciar projetos desenvolvidos individualmente ou em equipe.
A base de funcionamento do SCV é a gestão das versões dos arquivos de forma profissional, isto é, com controle e documentação.

O SCV mais utilizado hoje em dia é gerenciado pelo programa git e, normalmente, armazenado no servidor GitHub.

- Para usar o SCV git precisamos: Instalar o git (Etapa 1a) e ler um tutorial básico sobre seu uso (Etapa 1b).
- Para poder usar o servidor Github, teremos de criar uma conta neste site/servidor (Etapa 2).
- Passe os dados para o Prof. Bueno para que ele crie um repositório para o projeto (Etapa 3).
- Na (Etapa 4), iremos criar uma cópia local do projeto (uma cópia na sua máquina).
- Finalmente, na (Etapa 5), atualizamos o projeto localmente e depois enviamos para o servidor github.

Em resumo: 
para poder trabalhar com o git e github primeiro você tem de entender que vai ter uma cópia dos arquivos do "ProjetoEngenharia" em seu computador e uma cópia no servidor do Github. E que você irá usar o programa git, instalado em sua máquina, para gerenciar as versões de seu projeto.

Veja a seguir as etapas e instruções para ter seu próprio repositório.
 
Etapa 1) Se ainda não instalou, instale o programa git no seu computador.
Site: https://git-scm.com/

Após instalar sugiro ler um tutorial básico de uso do git.
Depois de ler um tutorial vale assistir alguns vídeos na internet.

Etapa 2) Criar uma conta no github
Agora você deve criar sua conta no servidor github (se ainda não tem).
Logue no navegador usando seu gmail institucional.
Entre no site https://github.com e crie sua conta, login e senha (usando gmail institucional).
Anote seus dados para não esquecer!

Etapa 3) Passe os seguintes dados para o Prof Bueno (bueno@lenep.uenf.br)
Título do projeto de engenharia: "título....blablabla"
Nome completo dos membros da equipe:
- nome completo <emailInstitucional>
- nome completo <emailInstitucional>
- nome completo <emailInstitucional>

O professor vai criar um repositório para o projeto de vocês e compartilhar o link e instruções para que tenham acesso.

Etapa 4) Criar cópia local do projeto
Após receber o link para o projeto, algo como 
"https://github.com/ldsc/ProjetoEngenharia-TituloXX"
você deve usar o programa git para baixar o projeto para sua máquina.
Abra um terminal e faça o download do modelo de projeto, abaixo os comandos para um terminal em máquina GNU/Linux ou Windows:
cd
mkdir workdir
cd workdir
git clone https://github.com/ldsc/ProjetoEngenharia-TituloXX

O comando "git clone endereço" copia para sua máquina o projeto localizado no "endereço".
 
Pronto o modelo já esta no servidor github (Endereço: https://github.com/ldsc/ProjetoEngenharia-TituloXX)
e já esta no seu computador (caminho ~/workdir/ProjetoEngenharia-TituloXX).

PS: um modelo genérico esta aqui: 
https://github.com/ldsc/ModeloDocumento-ProjetoEngenharia-ProgramacaoPratica

Etapa 5) Modifique os arquivos no seu computador e envie para o servidor.
Modifique os arquivos no seu computador incluindo os arquivos do projeto usando o editor LyX, as figuras/diagramas-UML usando o umbrello ou outro editor de arquivos UML, os códigos usando uma IDE qualquer. Depois registre as alterações feitas:
git commit -m "o que você alterou"

E então sincronize seus arquivos locais com os arquivos do servidor usando o comando:
git push

Para maiores detalhes de uso do git/github consulte livros na biblioteca do LENEP/CCT/UENF, livros sobre git e github, sites e tutoriais.
Alguns sites como:
https://github.com/
https://git-school.github.io/visualizing-git/#free
https://learngitbranching.js.org/?locale=pt_BR
Ensinam você a usar os comandos básicos do git e mostram o que esta acontecendo.

Etapa 6)
Depois que estiver tudo funcionando atualize este arquivo, apagando estas instruções e colocando informações específicas do projeto;
Lembrando que sempre adicione informações sobre:
- UENF
- CCT
- LENEP
- Disciplina
- Professor
- Ano/semestre
- Nome membros da equipe
isto facilita achar informações sobre o projeto.
