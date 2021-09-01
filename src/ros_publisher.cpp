#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>
//comment
int main(int argc, char **argv) {
  ros::init(argc, argv, "ros_topic_publisher");
  ros::NodeHandle nh;
  ros::Publisher topic_pub = nh.advertise<std_msgs::Int32>("/numbers",10);

	ros::Rate rate(10);
	
	int count = 0;
	while ( ros::ok() ) {
		
		std_msgs::Int32 msg;
		msg.data = count++;
		
		ROS_INFO("%d", msg.data);
		topic_pub.publish(msg);
	
		rate.sleep();
	}
  return 0;
}
