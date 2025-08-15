#include "rclcpp/rclcpp.hpp"

using rclcpp::init;
using rclcpp::spin;
using rclcpp::shutdown;
using rclcpp::TimerBase;
using rclcpp::Node;



using namespace std::chrono_literals; // Para usar 1s, 500ms, etc.

class MyNode : public Node
{
    public:
        MyNode() : Node("cpp_hello_world_node"), counter_(0)
        {
            RCLCPP_INFO(this->get_logger(), "Hello world");
            timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&MyNode::timerCallback, this));
        }
    private:
        void timerCallback()
        {
            RCLCPP_INFO(this->get_logger(), "Hello %d", counter_);
            counter_++;
        } 
        TimerBase::SharedPtr timer_;
        int counter_;
};

int main(int argc, char **argv){
    init(argc, argv);
    //Create a pointer Object RCL CPP
    auto node = std::make_shared<MyNode>();
    spin(node);
    shutdown();
    return 0;
}