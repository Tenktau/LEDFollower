import sensor
import image
import time
import math
import json
from pyb import UART

uart = UART(2, 115200)

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QQVGA)
sensor.skip_frames(time=2000)
sensor.set_auto_gain(False)
sensor.set_auto_whitebal(False)
clock = time.clock()

tag_families = 0
tag_families |= image.TAG36H11

def family_name(tag):
    if tag.family() == image.TAG36H11:
        return "TAG36H11"

while True:
    clock.tick()
    img = sensor.snapshot()
    for tag in img.find_apriltags(
        families=tag_families
    ):  # defaults to TAG36H11 without "families".
        img.draw_rectangle(tag.rect(), color=(255, 0, 0))
        img.draw_cross(tag.cx(), tag.cy(), color=(0, 255, 0))
        tag_rot = ((180 * tag.rotation()) / math.pi)
        data = {
        "tag_id":tag.id(),
        "pos_x":tag.cx(),
        "pos_y":tag.cy(),
        "tag_rot":tag_rot
        }
        msg = json.dumps(data)
        uart.write(msg + '\n')
        print("==================\nSending fllowing json message through UART: \n",msg)
#    print(clock.fps())
