#include "rclcpp/rclcpp.hpp"


int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    //Create a pointer Object RCL CPP
    auto node = std::make_shared<rclcpp::Node>("cpp_hello_world_node");
    RCLCPP_INFO(node->get_logger(), "Hello world");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}