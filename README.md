# Image Transport Bug
## Build
```shell
mkdir -p tmp_ws/src && cd tmp_ws/src && \
git clone https://github.com/mhubii/image_transport_bug.git && cd .. && \
colcon build
```
## Run
```shell
source install/setup.bash && \
ros2 run tmp tmp
```
- Expected output: [tmp_node]: N subscriptions: 1
- Actual output: [tmp_node]: N subscriptions: 0
Can be mitigated by building `image_common` from source, ie
```shell
cd src && \
git clone -b foxy https://github.com/ros-perception/image_common.git && cd .. && \
colcon build --allow-overriding image_transport
```
Then, re-run.
