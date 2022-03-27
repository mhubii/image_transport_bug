#include <rclcpp/rclcpp.hpp>
#include <image_transport/image_transport.hpp>


void cb(const sensor_msgs::msg::Image::ConstSharedPtr) { return; }

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("tmp_node");

    std::string topic = "image";
    auto pub = image_transport::create_camera_publisher(node->shared_from_this().get(), topic);
    auto sub = image_transport::create_subscription(node->shared_from_this().get(), topic, cb, "raw");

    while (rclcpp::ok()) {
        RCLCPP_INFO(node->get_logger(), "N subscriptions: %d", pub.getNumSubscribers());
        rclcpp::spin_some(node);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    rclcpp::shutdown();
}
