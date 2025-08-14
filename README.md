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