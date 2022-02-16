# PortonApp
Se desarrolla un nodo IoT que activa una puerta de garaje mediante una aplicación en el celular o un botón integrado.

Se tiene el objetivo de reemplazar los controles de RF de 315MHz que activan motores de puertas de garaje por smartphones, esta actualización introduce al sistema en la industria 4.0 al enlazarse con un nodo de internet; además diversifica las opciones de acceso, posibilita rutinas de automatización y evita el uso de los dispositivos «programadores» no incluidos en la compra del sistema de garaje. El punto pernicioso es que la activación con un smartphone puede ser molesta pues lleva un poco más de tiempo, el hardware requiere un continuo suministro eléctrico aunque esto también evita el uso de pilas de litio CR2032 y también el sistema es vulnerable a ataques MiTM y spoofing.

Es conveniente el uso del ESP8285 para evitar disparos en falso a causa de interrupciones en la red eléctrica, o en su defecto añadir un retardo en la activación del relevador. Otra opción es reprogramar un nodo tipo Sonoff para hacer uso de una App propia.
