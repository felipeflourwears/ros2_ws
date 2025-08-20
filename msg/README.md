# MSG ROS2

## Types of msg


List all messages in a package:  

```bash
ros2 interface list | grep geometry_msgs/msg
```

```bash
flourwears@flourwears:~$ ros2 interface show example_interfaces/msg/String
# This is an example message of using a primitive datatype, string.
# If you want to test with this that's fine, but if you are deploying
# it into a system you should create a semantically meaningful message type.
# If you want to embed it in another message, use the primitive data type instead.
string data
flourwears@flourwears:~$ 
flourwears@flourwears:~$ ros2 interface show geometry_msgs/msg/Vector3
# This represents a vector in free space.

# This is semantically different than a point.
# A vector is always anchored at the origin.
# When a transform is applied to a vector, only the rotational component is applied.

float64 x
float64 y
float64 z
flourwears@flourwears:~$
flourwears@flourwears:~$ ros2 interface show example_interfaces/msg/Byte
# This is an example message of using a primitive datatype, byte.
# If you want to test with this that's fine, but if you are deploying
# it into a system you should create a semantically meaningful message type.
# If you want to embed it in another message, use the primitive data type instead.
byte data
flourwears@flourwears:~$ 
```
