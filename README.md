# Workspace ROS2

## Build

To build the workspace

Only create the main folder and into the src
```bash
colcon build


flourwears@flourwears:~/Documentos/Github/ros2_ws$ ls
build  install  log  README.md  src
flourwears@flourwears:~/Documentos/Github/ros2_ws$ 
```

## Configuration

Add the path from workspace(install/setup.bash) to .bashrc into the final line:

```bash
flourwears@flourwears:~/Documentos/Github/ros2_ws/install$ pwd
/home/flourwears/Documentos/Github/ros2_ws/install
flourwears@flourwears:~/Documentos/Github/ros2_ws/install$ ls
COLCON_IGNORE     local_setup.ps1  _local_setup_util_ps1.py  local_setup.zsh  setup.ps1  setup.zsh
local_setup.bash  local_setup.sh   _local_setup_util_sh.py   setup.bash       setup.sh
flourwears@flourwears:~/Documentos/Github/ros2_ws/install$ 
```
Into:

```bash
sudo nano .bashrc

...
source /opt/ros/jazzy/setup.bash
source ~/Documentos/Github/ros2_ws/install/setup.bash

```

## Packages

### Python

```bash
flourwears@flourwears:~/Documentos/Github/ros2_ws$ cd src/
flourwears@flourwears:~/Documentos/Github/ros2_ws/src$ ros2 pkg create my_py_pkg --build-type ament_python --dependencies rclpy 
flourwears@flourwears:~/Documentos/Github/ros2_ws$ colcon build
flourwears@flourwears:~/Documentos/Github/ros2_ws$ colcon build --packages-select my_py_pkg

```

### Without build always you can use(optional for debugging quickly)
```bash
flourwears@flourwears:~/Documentos/Github/ros2_ws$ colcon build --packages-select my_py_pkg --symlink-install
```

### Run Python Package
```bash
flourwears@flourwears:~/Documentos/Github/ros2_ws$ source install/setup.bash
flourwears@flourwears:~/Documentos/Github/ros2_ws$ ros2 run my_py_pkg py_node_lf 

```
### C++

```bash
flourwears@flourwears:~/Documentos/Github/ros2_ws$ cd src/
flourwears@flourwears:~/Documentos/Github/ros2_ws/src$ ros2 pkg create my_cpp_pkg --build-type ament_cmake --dependencies rclcpp
flourwears@flourwears:~/Documentos/Github/ros2_ws$ colcon build
flourwears@flourwears:~/Documentos/Github/ros2_ws$ colcon build --packages-select my_cpp_pkg

```

### Run C++ Package
```bash
flourwears@flourwears:~/Documentos/Github/ros2_ws$ source install/setup.bash
flourwears@flourwears:~/Documentos/Github/ros2_ws$ ros2 run my_cpp_pkg cpp_node_lf 

```

# Quick Start for ROS2 Package

### 1. Go to your workspace
```bash
cd ~/ros2_ws
```

### 2. Build your package
```bash
colcon build --packages-select <package_name>
```

### 3. Source the workspace (in every new terminal)
```bash
source install/setup.bash
```
Or just put into .bashrc global 

### 4. Run your node
```bash
ros2 run <package_name> <node_name>
```

# Compile again

### 1. Go to your workspace
```bash
cd ~/ros2_ws
```

### 2. Delete these folders
```bash
sudo rm -rf build install log
```

### 3. Build your packages
```bash
colcon build
```

## Rename a Node
```bash
flourwears@flourwears:~/Documentos/Github/ros2_ws$ ros2 run my_py_pkg py_node_lf --ros-args -r __node:=sensorRename
[INFO] [1755281930.683918515] [sensorRename]: Hello world
[INFO] [1755281931.685696451] [sensorRename]: Hello 0
[INFO] [1755281932.685636674] [sensorRename]: Hello 1
```

## To see the nodes, topics or info
```bash
flourwears@flourwears:~$ ros2 node list
/robots_news_station_node

flourwears@flourwears:~$ ros2 topic list
/parameter_events
/robots_news
/rosout

flourwears@flourwears:~$ ros2 topic info /robots_news
Type: example_interfaces/msg/String
Publisher count: 1
Subscription count: 0
flourwears@flourwears:~$ 

flourwears@flourwears:~$ ros2 node info /robots_news_station_node 
/robots_news_station_node
  Subscribers:

  Publishers:
    /parameter_events: rcl_interfaces/msg/ParameterEvent
    /robots_news: example_interfaces/msg/String
    /rosout: rcl_interfaces/msg/Log
  Service Servers:
    /robots_news_station_node/describe_parameters: rcl_interfaces/srv/DescribeParameters
    /robots_news_station_node/get_parameter_types: rcl_interfaces/srv/GetParameterTypes
    /robots_news_station_node/get_parameters: rcl_interfaces/srv/GetParameters
    /robots_news_station_node/get_type_description: type_description_interfaces/srv/GetTypeDescription
    /robots_news_station_node/list_parameters: rcl_interfaces/srv/ListParameters
    /robots_news_station_node/set_parameters: rcl_interfaces/srv/SetParameters
    /robots_news_station_node/set_parameters_atomically: rcl_interfaces/srv/SetParametersAtomically
  Service Clients:

  Action Servers:

  Action Clients:

flourwears@flourwears:~$ ros2 topic echo


```