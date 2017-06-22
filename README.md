# ReadME

## Trabalho 2 de Técnicas de programação


## Índice
   * 1 [Objetivo](#1-objetivo)<br />
   <t>1.1 [Descrição](#11-descrição)<br />
   * 2 [Requisitos](#2-requisitos)<br />
   <t>2.1 [Utilizado](#21-utilizado)<br />
   <t>2.2 [Instalações](#22-instalações)<br />
   * 3 [Build Compilation](#3-build-compilation)<br />
   * 4 [Diagramas](#4-diagramas)<br />
   <t> 4.1 [Diagrama de sequência](#41-diagrama-de-sequência)
   <t> 4.2 [Diagrama de classe](#41-diagrama-de-sequência)
   * 5 [Doxygen](#5-doxygen)
   * 6 [Visão Computacional](#6-visão-computacional)

### 1 Objetivo
 <p>
 Aprender e trabalhar com a linguagem C++, implementando e aplicando conceitos ensinados em sala, incluindo detecção facial, banco de dados e manipulação do GitHub.
 </p>

### 1.1 Descrição
#### Sistema de controle de acesso
<p>
Simular um sistema para ser utilizado no Laboratório de Informática (LINF) da Universidade de Brasília que faz o controle de acesso, modelando por cadastramento, tipo de usuário, detecção facial e reservas.
</p><br />

### 2 Requisitos

 * Compilador g++
 * Editor de texto
 * Biblioteca de processamento de imagens
 * Ferramenta de versionamento
 * Framework para criação de interface gráfica
 * Banco de dados

 #### 2.1 Utilizado

 * Terminal linux
 * Compilador g++ Ubuntu 6.2.0-5ubuntu12 20161005
 * Atom
 * GitHub
 * OpenCV
 * Qt Creator 5.9
 * SQLite

 #### 2.2 Instalações

 ##### Compilador g++

```
$ sudo apt-get install g++
```

##### Atom

```
https://atom.io/
```

##### GitHub

```
$ sudo apt-get install git
```
##### OpenCV
```
  Tutorial criado por: Flavio Amaral e Silva; Lukas Lorenz de Andrade; Marcella Pantarotto.

  Para baixar a OPENCV-3.2.0 com a Contrib (extensão) use os seguintes comandos no terminal:
  - Para baixar

  	wget https://codeload.github.com/opencv/opencv_contrib/tar.gz/3.2.0
  	wget https://codeload.github.com/opencv/opencv/tar.gz/3.2.0

  - Para mover para o diretório home

  	mv Downloads/opencv_contrib-3.2.0.tar.gz ./
  	mv Downloads/opencv-3.2.0.tar.gz ./

  - Para extrair as pastas

  	tar xvfz opencv-3.2.0.tar.gz
  	tar xvfz opencv_contrib

  - Agora, abra o repositório opencv-3.2.0 e edite o arquivo CMakeLists.txt da seguinte forma:

  Delete:

  404	    if(NOT DEFINED OPENCV_CONFIG_INSTALL_PATH)		
  405	      math(EXPR SIZEOF_VOID_P_BITS "8 * ${CMAKE_SIZEOF_VOID_P}")
  406	      if(LIB_SUFFIX AND NOT SIZEOF_VOID_P_BITS EQUAL LIB_SUFFIX)
  407	        ocv_update(OPENCV_CONFIG_INSTALL_PATH lib${LIB_SUFFIX}/cmake/opencv)
  408	      else()
  409	        ocv_update(OPENCV_CONFIG_INSTALL_PATH share/OpenCV)
  410	      endif()
  411	    endif()

  E substituia por:

  403	    ocv_update(OPENCV_CONFIG_INSTALL_PATH lib${LIB_SUFFIX}/cmake/opencv)

  OBS: Os números são apenas indicativos das linhas em que é necessária a operação.
  Salve o arquivo e feche o txt.

  - Abra o repositório opencv_contrib-3.2.0/modules/optflow/samples/ e edite o arquivo motempl.py da seguinte forma:
  Substituia a linha 40:

  39	    if ret == False:
  40	        break
  41	    h, w = frame.shape[:2]
  42	    prev_frame = frame.copy()

  Por:
  40	        print("could not read from video source")
  41	        sys.exit(1)

  Salve o arquivo txt e feche-o.

  Execute os seguintes comandos:

	cd opencv-3.2.0
	mkdir build
	cd build

	cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-3.2.0/modules ..

	make -j4

	sudo make install

	sudo ldconfig

Pronta para uso!! ( ͡° ͜ʖ ͡°)
```
#### Qt Creator

[Passo-a-passo](https://wiki.qt.io/Install_Qt_5_on_Ubuntu)

#### SQLite

```
$ sudo apt-get install sqlite3 libsqlite3-dev
```

### 3 Build Compilation
Entrar na pasta ProjetoTP1 e usar o seguinte código
```
$ cd ProjetoTP1
$ make ProjetoTP1.pro -spec linux-g++
$ make all
$ make clean
$ chomd 775 ProjetoTP1_EXEC
./ProjetoTP1_EXEC
```

### 4 Diagramas

#### 4.1 Diagrama de Sequência
![Diagrama de sequência](https://github.com/Marcos-/TP1-trabalho2/blob/master/assets/%C3%ADndice.png)

#### 4.2 Diagrama de Classe
Doxygen não esta gerando

### 5 Doxygen

Pasta HTML e Latex


### 6 Visão Computacional

Uso da biblioteca OPENCV 3.2 e do módulo de reconhecimento facial parar a implementação do sistema de login via detecção facial
- Uso do Cascade lbpcascade_frontalface.xml, para a deteção facil.
- Model para trainamento e reconhecimento usando o algoritmo LBPH de reconhecimento :
  - radius = 3, neighbors = 12, grid_x = 12, grid_y = 12, threshold = 320.0
  - treinamento do model com 10 fotos.
