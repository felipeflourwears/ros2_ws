# Conceptos clave de ROS 2

Este documento explica los conceptos fundamentales de ROS 2 y cómo se relacionan entre sí.

## Tabla de conceptos

| Concepto  | Qué es / Función | Cómo se usa / Comunicación | Ejemplo práctico |
|-----------|-----------------|---------------------------|-----------------|
| **Nodo** | Unidad básica de ejecución en ROS 2. Es un programa que hace algo, puede publicar o suscribirse a datos. | Cada nodo corre de manera independiente y puede comunicarse con otros nodos. | Un nodo que lee la cámara o un sensor de temperatura. |
| **Topic** | Canal de comunicación para **envío de datos asíncrono** entre nodos. | Un nodo **publica** mensajes a un topic; otros nodos **se suscriben** a ese topic. | Nodo A publica la posición del robot; nodo B recibe esa posición para mover un brazo. |
| **Service** | Comunicación **sincrónica** que sigue el patrón **request/response** (petición/respuesta). | Un nodo hace un request a otro nodo que ofrece un service y espera la respuesta. | Nodo A pide al nodo B que haga un cálculo de trayectoria y espera el resultado. |
| **Action** | Similar a un service, pero permite **progreso continuo** y cancelación de tareas largas. | Nodo A inicia una acción en nodo B, recibe feedback y resultado final. | Mover un robot a un punto lejano con actualizaciones de progreso. |
| **Parameter** | Configuración o valor que un nodo puede **leer o cambiar en tiempo de ejecución**. | Se definen al iniciar el nodo o se modifican mientras corre. | Velocidad máxima de un motor que se puede ajustar sin reiniciar el nodo. |
| **Mensaje** | Estructura de datos que se envía a través de topics o services. | Define qué información se puede enviar y cómo. | Un mensaje de posición tiene `x, y, z`. |

    
## Diferencias clave resumidas

<ul>
    <li><strong>Topics</strong>: comunicación asíncrona, flujo de datos continuo, no espera respuesta.</li>
    <li><strong>Services</strong>: comunicación síncrona, un request y una respuesta, ideal para tareas puntuales.</li>
    <li><strong>Actions</strong>: como services pero para tareas largas, con progreso y posibilidad de cancelación.</li>
    <li><strong>Nodos</strong>: programas que ejecutan lógica y se comunican mediante topics, services o actions.</li>
    <li><strong>Parameters</strong>: configuración dinámica de nodos que se puede cambiar en tiempo de ejecución.</li>
</ul>
---