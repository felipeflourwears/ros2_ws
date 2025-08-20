# Conceptos clave de ROS 2

Este documento explica los conceptos fundamentales de ROS 2 y cómo se relacionan entre sí.

## Tabla de conceptos

    <table>
        <tr>
            <th>Concepto</th>
            <th>Qué es / Función</th>
            <th>Cómo se usa / Comunicación</th>
            <th>Ejemplo práctico</th>
        </tr>
        <tr>
            <td><strong>Nodo</strong></td>
            <td>Unidad básica de ejecución en ROS 2. Es un programa que hace algo, puede publicar o suscribirse a datos.</td>
            <td>Cada nodo corre de manera independiente y puede comunicarse con otros nodos.</td>
            <td>Un nodo que lee la cámara o un sensor de temperatura.</td>
        </tr>
        <tr>
            <td><strong>Topic</strong></td>
            <td>Canal de comunicación para <strong>envío de datos asíncrono</strong> entre nodos.</td>
            <td>Un nodo <strong>publica</strong> mensajes a un topic; otros nodos <strong>se suscriben</strong> a ese topic.</td>
            <td>Nodo A publica la posición del robot; nodo B recibe esa posición para mover un brazo.</td>
        </tr>
        <tr>
            <td><strong>Service</strong></td>
            <td>Comunicación <strong>sincrónica</strong> que sigue el patrón <strong>request/response</strong> (petición/respuesta).</td>
            <td>Un nodo hace un request a otro nodo que ofrece un service y espera la respuesta.</td>
            <td>Nodo A pide al nodo B que haga un cálculo de trayectoria y espera el resultado.</td>
        </tr>
        <tr>
            <td><strong>Action</strong></td>
            <td>Similar a un service, pero permite <strong>progreso continuo</strong> y cancelación de tareas largas.</td>
            <td>Nodo A inicia una acción en nodo B, recibe feedback y resultado final.</td>
            <td>Mover un robot a un punto lejano con actualizaciones de progreso.</td>
        </tr>
        <tr>
            <td><strong>Parameter</strong></td>
            <td>Configuración o valor que un nodo puede <strong>leer o cambiar en tiempo de ejecución</strong>.</td>
            <td>Se definen al iniciar el nodo o se modifican mientras corre.</td>
            <td>Velocidad máxima de un motor que se puede ajustar sin reiniciar el nodo.</td>
        </tr>
        <tr>
            <td><strong>Mensaje</strong></td>
            <td>Estructura de datos que se envía a través de topics o services.</td>
            <td>Define qué información se puede enviar y cómo.</td>
            <td>Un mensaje de posición tiene <code>x, y, z</code>.</td>
        </tr>
    </table>
    
## Diferencias clave resumidas

<ul>
    <li><strong>Topics</strong>: comunicación asíncrona, flujo de datos continuo, no espera respuesta.</li>
    <li><strong>Services</strong>: comunicación síncrona, un request y una respuesta, ideal para tareas puntuales.</li>
    <li><strong>Actions</strong>: como services pero para tareas largas, con progreso y posibilidad de cancelación.</li>
    <li><strong>Nodos</strong>: programas que ejecutan lógica y se comunican mediante topics, services o actions.</li>
    <li><strong>Parameters</strong>: configuración dinámica de nodos que se puede cambiar en tiempo de ejecución.</li>
</ul>
---