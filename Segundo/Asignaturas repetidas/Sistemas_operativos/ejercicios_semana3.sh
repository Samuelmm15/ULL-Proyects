# Nombre: Samuel Martín Morales
# Grupo: PE 103

# 1. Contar el número de procesos en nuestra sesión que están ejecutándose en segundo plano en nuestra sesión
jobs | wc -l

# 2. Contar el número de procesos que están en estado detenidos entre los de nuestra sesión
jobs | grep Detenido | wc -l

# 3. Mostrar el nombre de los procesos que se están ejecutando en segundo plano
jobs | tr -s ' ' ' ' | cut -d' ' -f3

# 4. Contar el número total de procesos que estamos ejecutando
ps -ax | wc -l

# 5. Sacar un listado de todos los directorios que hay en nuestro directorio actual
ls -a

# 6. Contar el número de programas alojados en nuestro directorio actual donde el grupo otros tiene permisos de ejecución
