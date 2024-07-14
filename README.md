# Procesos Estadísticos
Trabajo práctico realizados en la cátedra de Algoritmos y Estructuras de Datos de la Universidad Tecnológica Nacional - FRRe.

Este programa realiza un proceso estadístico con datos sobre mediciones realizadas durante el período 1990-2022 de las emisiones de CO<sub>2</sub>, en el continente americano. El trabajo se desarrolló en el marco de una exposición acerca de los Objetivos de Desarrollo Sostenible (ODS), destacando la importancia de monitorear y reducir las emisiones de gases de efecto invernadero para alcanzar metas globales de sostenibilidad.

El funcionamiento se apoya en la utilización de una matriz, en la cual se cargan todos los datos a partir de un archivo CSV. Durante el proceso de llenado de la misma, también se realiza el cálculo de los totales parciales por año y país, como así también el total general. Esto permite obtener fácilmente datos de interés como el país donde se produjo una mayor contaminación, o comparaciones entre los datos de emisión entre diversos años y países.

## Notas
* El programa fue enteramente desarrollado y probado en sistemas operativos GNU/Linux, más específicamente en Debian 12 Bookworm. Utilicé el compilador **gcc**, en su versión 12.2.0.

* El programa fue compilado con el comando `gcc lab_ods.c -lm -o ods`.
