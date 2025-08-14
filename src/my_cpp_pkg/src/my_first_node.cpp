#include "rclcpp/rclcpp.hpp"
using namespace std::chrono_literals;

class MyNode : public rclcpp::Node
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
        rclcpp::TimerBase::SharedPtr timer_;
        int counter_;
};

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    //Create a pointer Object RCL CPP
    auto node = std::make_shared<MyNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}