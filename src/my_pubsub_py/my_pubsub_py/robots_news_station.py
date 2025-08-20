#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String
 
 
class RobotNewStationNode(Node):
    def __init__(self):
        super().__init__("robots_news_station_node")
        self.robot_name_ = "C1-10P"
        self.publisher_ = self.create_publisher(String, "robots_news", 10)
        self.timer_ = self.create_timer(0.5, self.publish_news)
        self.get_logger().info("Robot New Station has been started.")
        

    def publish_news(self):
        msg = String()
        msg.data = "Hi, this is " + self.robot_name_ + " from the robot news station"
        self.publisher_.publish(msg)
        self.get_logger().info(f"Publish: {msg.data}")
 
 
def main(args=None):
    rclpy.init(args=args)
    node = RobotNewStationNode()
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()