# 视觉-灯光跟踪交互（暂名） / LEDFollower

## 项目介绍 / Project Intro

此项目为本人在参与**Vision Board 创客营活动**第二阶段（应用作品设计）过程中所产出的内容。主要内容是实现 LED 矩阵实时响应 AprilTag 的坐标进行同步移动。

This project is an output of my participation in **Vision Board Creator Camp** Phase II (Application Design). The main content is to realize the synchronized movement of the LED matrix in real time in response to the coordinates of the AprilTag.

> [“Vision Board 创客营”](https://bbs.elecfans.com/try_VisionBoard.html)是由[电子发烧友论坛](https://bbs.elecfans.com/)与 [RT-Thread](https://www.rt-thread.org/) 共同主办的围绕新品 [Vision Board 开发板](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/hw-board/ra8d1-vision-board/ra8d1-vision-board?id=vision-board-%e5%bc%80%e5%8f%91%e6%9d%bf)进行一系列评测的活动。  
> The ["Vision Board Creator Camp"](https://bbs.elecfans.com/try_VisionBoard.html) is an event co-sponsored by <https://bbs.elecfans.com> and [ RT-Thread](https://www.rt-thread.org/), featuring a series of reviews around the new ["Vision Board" demo board](https://www.rt-thread.org/document/site/#/rt-thread-version/rt-thread-standard/hw-board/ra8d1-vision-board/ra8d1-vision-board?id=vision-board-%e5%bc%80%e5%8f%91%e6%9d%bf).

## 实现方案 / Programs of Realization

总共涉及三款硬件，具体内容为：使用 **Vision Board** 作为上位机，并通过 OpenMV 程序获取 AprilTag 实时坐标、再通过 UART 串口通讯发送坐标信息给下位机；**Arduino(Uno)** 作为下位机接收坐标信息并将信息转化为 LED 矩阵坐标，再通过 FastLED 库实现对 **WS2812b** 灯带的 LED 操控。

In total, there are three pieces of hardware involved, as detailed below: Using **Vision Board** as the host computer, and through the OpenMV program to obtain the AprilTag real-time coordinates, and then through the UART serial communication to send coordinate information to the lower computer; **Arduino(Uno)** as the lower computer to receive coordinate information and information into the LED matrix coordinates, and then through the FastLED library to achieve the LED manipulation of the **WS2812b**.

## 开发现况 / Development Status

由于手头上的 WS2812b 灯带连接触点氧化、无法焊接导线从而成为方形矩阵，故暂时放弃二维矩阵的模式，转而以初步实现一维矩阵（5 个 LED 灯珠）为目标。

Since the existing WS2812b strip has oxidized connecting points and it is not possible to solder wires to make a square matrix, the two-dimensional matrix model has been abandoned for the time being in favor of a preliminary realization of a one-dimensional matrix (5 LED beads).

### 待办 / TODO

- [x] 调通上位机与下位机之间的 UART 通讯 / Realize UART communication between the upper and lower units
- [ ] 当识别不同编号的 AprilTag 时，灯带发出不同颜色 / Different colors are emitted when different numbered AprilTags are recognized
- [ ] 实现二维 LED 矩阵形式的跟踪效果 / Realization of the tracking effect in the form of a 2D LED matrix
