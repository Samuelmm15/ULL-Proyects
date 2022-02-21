# Práctica 2. Instalación y configuración de Visual Studio Code

## Índice

1. [Pasos Previos.](#id1)

2. [Instalación de Visual Studio Code](#id2)

3. [Configuración de Visual Studio para realizar SSH](#id3)

4. [Primer proyecto en TypeScript](#id4)

5. [Live Share Extension Pack](#id5)

## Pasos previos<a name="id1"></a>

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

## Instalación de Visual Studio Code<a name="id2"></a>

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

## Configuración de Visual Studio Code para conectarse a nuestra máquina remota a través del comando SSH<a name="id3"></a>

Suponiendo que la máquina virtual de la asignatura ha sido creada en la [Práctica 1](https://ull-esit-inf-dsi-2122.github.io/prct01-iaas/)
se realiza la descarga de la extensión de Visual Studio Code denominada como *Remote - SSH* que permite
realizar conexiones mediante el protocolo **SSH** a través del editor. Hay que tener en cuenta que si se
completó la configuración del fichero `~/.ssh/config` de la máquina local usada, únicamente se realiza la
conexión a la máquina virtual mediante la sentencia `ssh iaas-dsi`.

Una vez se realiza la conexión a la máquina virtual de la asignatura, ya se puede realizar el [primer proyecto en TypeScript](link-para-el-primer-proyecto).

## Primer proyecto en TypeScript: "Hola Mundo"<a name="id4"></a>

Antes de comenzar con la creación del primer proyecto en [TypeScript](https://es.wikipedia.org/wiki/TypeScript)
, es necesario realizar la instalación de un paquete denominado [ESlint](https://marketplace.visualstudio.com/items?itemName=dbaeumer.vscode-eslint)
, esta extensión de visual studio se encarga de analizar el código de la aplicación, detectar problemas por
medio de patrones y si puede, resolver los problemas el mismo, además, ESLint cuenta con una serie de reglas
por defecto.

Por otra parte, si no se posee el compilador de TypeScript instalado en la máquina virtual o la máquina la cúal
se vaya ha hacer uso, es necesaria la instalación del compilador mediante los comandos:

```
[~()]$ npm install --global typescript
```

Con todo esto anterior cumplimentado, se da comienzo al primer proyecto desarrollado en TypeScript. Para ello,
tras la creación de un directorio en la máquina dónde va a ser almacenado dicho proyecto, se hace uso del
comando:

```
[~/directorio-ejemplo()]$ npm init --yes
```

Tras esto anterior se obtiene la siguiente salida:

```
Wrote to /home/usuario/directorio-ejemplo/package.json:

{
  "name": "hello-world",
  "version": "1.0.0",
  "description": "",
  "main": "index.js",
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "keywords": [],
  "author": "",
  "license": "ISC"
}
```

Todo esto anterior genera como resultado un fichero denominado **package.json** que se trata de un archivo de
definición o manifiesto para el proyecto, en el cual se especifican referencias al proyecto como el autor, la
versión y sobre todo las dependencias.

A continuación, se crea un fichero denominado como `tsconfig.json` en dónde se especifican las opciones para el
compilador de TypeScript. En este fichero se deben de incluir las líneas:

```
{
  "compilerOptions": {
    "target": "ES2018",
    "outDir": "./dist",
    "rootDir": "./src",
    "module": "CommonJS"
  }
}
```

Hay que tener en cuenta que en las opciones especificadas anteriormente, le indican al compilador de TypeScript
que en primer lugar, el tipo de estándar de JavaScript el cual se quiera que el código sea compatible. A
continuación se especifica que el código generado sea almacenado en el directorio `./dist`. En tercer lugar, se
especifica dónde se encuentra el código fuente escrito en TypeScript. Para finalizar, se indica un estándar
para cargar código desde ficheros.

Para finalizar, se crea un fichero de código TypeScript denominado como `index.ts` en el directorio que ha sido
especificado como directorio dónde se encuentra el código fuente del proyecto, para este ejemplo, se trata del
directorio `directorio-ejemplo/src`. Dentro de dicho fichero se añaden las líneas de código:

```
let myString: string = "Hola Mundo";
console.log(myString);
```

Tras esto anterior, se compila el código en TypeScript ejecutando el comando:

```
[~/directorio-ejemplo()]$ tsc
```

Para poder ejecutar el código JavaScript generado a partir del código TypeScript, se hace uso del comando:

```
[~/directorio-ejemplo()]$ node dist/index.js
Hola Mundo
```

## Extesión de Visual Studio Code **Visual Studio Live Share**<a name="id5"></a>

Para la correcta configuración de Visual Studio Code, se ha de instalar una extensión denominada como [Live Share Extension Pack](https://marketplace.visualstudio.com/items?itemName=MS-vsliveshare.vsliveshare-pack).
Esta extensión permite editar, depurar, chatear, compartir terminal, etc, con los compañeros de trabajo de cualquier proyecto. En este caso, para la prueba de dicha extensión he realizado una sesión con mi compañero @Daniele_Vitale dónde se ha podido probar la apertura de un fichero de código python y su ejecución. También se ha realizado una prueba del chat y de la edición de código en conjunto.
