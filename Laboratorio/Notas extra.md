---
title: ""
author: ""
date: ""
geometry: margin=1in
colorlinks: true
header-includes:
	- \usepackage{fvextra}
	- \DefineVerbatimEnvironment{Highlighting}{Verbatim}{breaklines,commandchars=\\\{\}}
---

Algunas cosas que estaría bueno que el programa tenga, por orden de importancia: 

* Una forma de automatizar la entrada de datos, así no me tengo que tomar el (gran) trabajo de acomodar todos los datos en una planilla de cálculo.
* Agregar un *log* de ejecución, almacenando todos los procesos que haya hecho el usuario.
* ¡Agregar a Curazao!

Algunas cosas que habría que testear un poco más a fondo:

* La entrada de datos del usuario desde la terminal. Quizás el método de `fgets` eliminando los saltos de línea con `strcspn` sean más seguro que las llamadas recursivas que hice (aunque, no encontré ningún problema por el momento con dicho método).