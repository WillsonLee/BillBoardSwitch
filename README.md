# BillboardSwitch

这是一个广告牌替换程序，使用`OpenCV`的单应矩阵将广告牌图片扣下来替换到目标图片上

1. 项目配置
- 要求：安装了`Qt5`，安装了`OpenCV`
   - 打开目录下`OpenCV.pri`文件重新配置本机的`opencv`的相关头文件路径与共享库路径；
   - 使用Qt Creator打开`BillboardSwitch.pro`文件即可编译运行
2. 程序使用

![](/home/lyx/workspace/Qt/BillboardSwitch/mainwindow.png)

- 加载目标图片（左图）与替换广告牌图片（右图）
- 然后鼠标选择对应点（如左边运动员广告牌四个角点对应右边图片的四个角点），鼠标选的点像素坐标会写在中间表格里；鼠标在图片中实时坐标会显示在数码显示板上
- 点击`run`替换，`save`保存结果；保存的文件名称路径可在右下角设置

输入图片为：

|                        目标图片                         |                       替换图片                        |
| :-----------------------------------------------------: | :---------------------------------------------------: |
| ![](/home/lyx/workspace/Qt/BillboardSwitch/street.jpeg) | ![](/home/lyx/workspace/Qt/BillboardSwitch/Miku.jpeg) |

将运动员广告牌替换成初音未来，输出结果为：

![](/home/lyx/workspace/Qt/BillboardSwitch/output.png)