# Práctica 2. Instalación y configuración de Visual Studio Code.

En esta segunda práctica de la asignatura `Desarrollo de Sistemas 
informáticos` se ha realizado la instalación y la configuración de [Visual 
Studio Code](https://code.visualstudio.com). Este se trata de un editor de 
código fuente desarrollado por Microsoft, Visual Studio Code incluye soporte 
para la depuración de código, control integrado de [Git](https://es.wikipedia.org/wiki/Githttps://es.wikipedia.org/wiki/Git)
, resaltado de sintaxis, y muchas más opciones en las que se puede indagar.

Antes de comenzar la práctica, como se puede observar en el [guión](https://ull-esit-inf-dsi-2122.github.io/prct02-vscode/) 
de esta, se recomienda la realización de dos cursos que son necesarios para 
entender el funcionamiento de las [GitHub Pages](https://platzi.com/blog/github-pages/#:~:text=GitHub%20Pages%20es%20un%20servicio,más%20de%205%20minutos%20configurar.) 
y de el uso de [Markdown](https://www.genbeta.com/guia-de-inicio/que-es-markdown-para-que-sirve-y-como-usarlo) 
para la creación de estas.

## Instalación de Visual Studio Code

En el caso de que no se tenga instalado el editor de código fuente, se ha de 
instalar haciendo uso de alguno de los **dos** métodos para ello, dependiendo 
del sistema operativo el cúal se haga uso para la realización de esta 
práctica.

En el caso de que se realice a través de [Windows](https://es.wikipedia.org/wiki/Microsoft_Windows) 
,[MacOS](https://es.wikipedia.org/wiki/MacOS), [Debian](https://es.wikipedia.org/wiki/Debian_GNU/Linux) 
o [Ubuntu](https://es.wikipedia.org/wiki/Ubuntu), se puede realizar la 
instalación a través de archivos descargados a través de la [página oficial](https://code.visualstudio.com).

Por otro lado, en el caso de distribuciones basadas en Linux como pueden ser 
Ubuntu, Debian, etc, existe otra posibilidad y es haciendo uso de la terminal 
de estos. Para poder instalar Visual Studio Code, se hace uso del comando:
```
smartin@smartin-proyect:~$ sudo apt install code
```
## Configuración de Visual Studio Code para conectarse a nuestra máquina remota a través del comando SSH

Suponiendo que la máquina virtual de la asignatura ha sido creada en la [Práctica 1](https://ull-esit-inf-dsi-2122.github.io/prct01-iaas/) se realiza la descarga de la extensión de Visual Studio Code denominada como *Remote - SSH* que permite realizar conexiones **SSH** a través del editor. 