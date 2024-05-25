# 看懂XCP协议



XCP全称Universal Calibration Protocol，是由ASAM (Association for Standardization of Automation and Measuring Systems,简称 ASAM)组织在2003年提出的可在不同的通信总线上进行标定的新型标定协议，这里的X代表不同的传输层上传输(CAN、Ethernet、FlexRay、SCI、SPI、USB)。

XCP的应用场景：上传ECU数据，实现对ECU内部变量进行观测；在线对ECU内部变量进行标定；ECU刷写程序或数据。数据仿真，周期性下载数据至ECU，通常用于快速原型；其中通常使用的是对变量的观测、标定以及刷写ECU。标准介绍XCP标准主要分为五部分：

Part 1 – Overview。XCP协议概述，包括XCP的特点描述以及XCP协议的基本原理。

Part 2 – Protocol Layer Specification。协议层进行详细的规范和说明，包括XCP数据包类型、格式以及各命令使用说明。

Part 3 – Transport Layer Specification。该部分包含5份文档，分别对应5个不同的传输层（CAN，Ethernet/TCP_IP，FlexRay，SxI/SCI&SPI，USB），规定不同总线下传输层的实现。

Part 4 – Interface Specification。该部分对A2L描述文件、秘钥与种子加解密、数据校验功能说明。

Part 5 – Example Communication Sequences。该部分描述了部分通信数据流，演示如何使用XCP协议的命令同ECU进行通讯。XCP通信协议方式XCP数据包主要有两种形式：传输控制命令的CTO(Command Transfer Object)和同步数据包DTO(Data Transfer Object)。

主从节点间的XCP通信方式如图1所示。

![img](https://img-blog.csdnimg.cn/img_convert/f37aff1bbfc3e01ba19e3c888736d90c.png)

图1 XCP主从机交互



1.CTO用于传输控制命令，包含五种形式：1.CMD(Protocol Command)，PID范围为xC0~0xFF，主机向从机发送的命令请求，从机据此识别命令。

![img](https://img-blog.csdnimg.cn/img_convert/381374fd27d3d6bb3ec18ad9b7a8154f.png)

2.RES(Transferring Command Responses)，PID值为0FF，从机在接收到主机的CMD后，当命令被执行成功时，从机向主机发送肯定响应数据包。

![img](https://img-blog.csdnimg.cn/img_convert/856be8ba52471547b75e38d185bd48c7.png)

3.ERR(Error Packets)，PID值为0XFE，当命令执行发生错误时，从机反馈错误数据包。

![img](https://img-blog.csdnimg.cn/img_convert/164bb624aab8f29f38e1c9847d6ac7bf.png)

4.EV(Event)，PID值为0xFD，当从机向主机报告一个异步的事件时，发送次数据包。

![img](https://img-blog.csdnimg.cn/img_convert/a2cfb2fc36a8dc2955e1a6faa110984e.png)

5.SERV(Service Request Packets)，PID值为0xFC，当从机需要主机做出某些动作时，从机向主机发送此数据包。

![img](https://img-blog.csdnimg.cn/img_convert/2018574a41cd135c5ff4967fefe2726d.png)





DTO数据包传输同步数据包DAQ(Data Acquisition)和同步激励数据STIM(Data Stimulation packet)。在DAQ模式下，从机周期性上传数据，STIM模式正好相反，主机周期性的向从机下载数据。基于CAN总线的XCP报文格式

在汽车ECU的标定中，通常使用CAN总线。

基于CAN的XCP报文帧结构如图2所示，其中PID用于标识XCP报文的类型，PID与任务的对应表如表1所示，

FILL用于描述报文对齐信息，DAQ表示DAQ列表的标识符，TIMSTAMP为可选项，Data存放数据。

![img](https://img-blog.csdnimg.cn/img_convert/af287cc715fabe341b6ba683edc297b7.png)

图2 基于CAN的XCP帧格式



![img](https://img-blog.csdnimg.cn/img_convert/6c7dfb2cfc120d5b8ee8a895f8d5bbd2.png)

表1 PID与任务的对应关系



## CAN通信最常用的标定协议--CCP与XCP

CCP协议（**[CAN](http://www.eeworld.com.cn/tags/CAN)** Calibration Protocol）

- CAN标定协议，基于CAN总线的标定协议

XCP协议（Universal Measurement and Calibration Protocol）

- 通用测试标定协议
- 可以应用在许多总线上



## **1  ASAM是什么组织？**

提及XCP协议，不得不从ASAM说起。

随着汽车电子的高速发展，汽车上的ECU越来越多，各控制器间协同工作，控制着不同的部件。

电子控制单元ECU作为汽车系统中的大脑，通过采集输入信息，比如加速踏板，制动踏板，巡航，起停等，采用特定的算法计算输出，为了达到理想的控制效果，算法中包含较多的可标定参数，根据不同的输入和工况等调整，ECU中的程序由软件工程师设计开发，而软件工程师并不能准确将这些参数设置成合理值，这些参数是需要在实验中根据我们追求的经济性、动力性、舒适性和满足排放法规等来设置，这部分工作是由标定工程师（或应用工程师）在软件开发后利用改变参数分析性能反复迭代最终测定，因此标定工程师就需要对不同参数进行获取（读操作）和标定（写操作）。这时候，就需要有个测量和标定标准来规范大家的操作。

在1990年代，几个德系OEM和TIER1—奥迪，宝马，奔驰，大众，BOSCH，ETAS和Vector等，一起成立了一个协会，叫做ASAM。

![img](https://img-blog.csdnimg.cn/img_convert/5dbc827637f333801c6e12944af0c287.png)

ASAM(Association for Standardisation of Automation and Measuring Systems，自动化和测量系统标准协会)是一个非营利性组织，是汽车工业中的标准协会，致力于数据模型，接口及语言规范等领域。不要小瞧这个协会，除了我们今天提到的测试和标定标准，还有诊断、ECU网络、软件开发、自动化测试、数据管理和分析、仿真等范畴都在遵循它制定的标准。

成立之初，ASAM发布的CCP（CAN Calibration Protocol）协议，它是一种基于CAN总线的ECU标定协议，采用CCP协议可以快速而有效地实现对汽车电控单元的标定。现在仍然有许多汽车厂商还在使用。

**2 XCP协议概述**

有了CCP协议后，ASAM意识到随着整车网络需求的发展，CAN总线已经无法满足整车需求，智能化和网联化要求FlexRay，以太网的加入。2003年左右，在CCP协议的基础上，ASAM又提出了XCP（Universal Measurement and Calibration Protocol）协议。“XCP”中"X"是Universal，通用的，表示能适配它能够支持多种底层网络协议和总线类型。

XCP的主要应用于测量和标定ECU内部参数。此协议能够使数据采集工作与ECU内部运行的任务和中断同步，从而保证每当ECU软件更新参数时，能快速采集到所需的参数值。基于以太网的XCP传输层协议可以使用TCP或UDP，不仅适用于物理控制单元，还可用于测量和调整虚拟控制单元。

![img](https://img-blog.csdnimg.cn/img_convert/9f6872b33dc54eceaeb4ce9844e498f9.png)

XCP允许对内存直接进行读写访问：这样在读访问中就可以用来测量来自内存的参数数值，写访问中就可以用于调整内存中参数的数值。

![img](https://img-blog.csdnimg.cn/20200921150914713.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3Vzc3RtaXJhY2xl,size_16,color_FFFFFF,t_70)

 

**3 XCP协议框架**

为了确保传输网络的独立性，XCP被分成一个协议和一个传输层。由于XCP在功能方面增强了很多，所以不能向后兼容CAN标定协议（CCP）。同时ASAM已经对XCP协议定义了下列传输层定为标准：

- 基于CAN的XCP
- 基于LIN的XCP
- 基于SxI（SPI、SCI）的XCP
- 基于以太网（TCP/UDP）的XCP
- 基于USB的XCP
- 基于FlexRay的XCP

![img](https://img-blog.csdnimg.cn/img_convert/0e00df674b6ce0a8324fbb5a0d925be7.png)

 

XCP由ASAM 标准化并且取代了古老的CAN标定协议（CCP）。相较于CCP协议，XCP在功能上做了许多改进，包括：

- 支持任何物理层协议，不仅限于CAN
- 优化了控制单元资源的利用率
- 同步数据激励
- 支持启动测量
- 通过块传输命令优化通信
- 即插即用配置
- 通过测量控件内的时间戳从而精确测量数据采集。

采用一主多从的模式，单个主机可以同时与多个从机通讯。主机通过下发命令与从机建立连接，解锁，读取数据，修改参数等操作。所有XCP通信都以名为“XCP数据包”的数据对象形式传输。

XCP数据包有两种类型：

命令传输对象（CTO：Command Transfer Object）被用来传输一般的控制命令：控制命令（CMD），命令响应（RES），错误包（ERR）事件包（EV）以及服务请求数据包（SERV）。

数据传输对象（DTO：Data Transfer Object）被用于传输同步数据采集数据（DAQ）和同步数据激励数据（STIM）。

- **CMD: Command**
- **RES: Response**
- **ERR: Error**
- **EV: Event**
- **SERV: Service Request Processor**
- **DAQ: Data Acquisition**
- **STIM: Stimulation**

![img](https://img-blog.csdnimg.cn/img_convert/4291a257741d7fae6fe671e319bbc38a.png)

XCP实现测量与控制设备中的事件同步进行，从而确保测得值具有相关性。待测量的信号可以在每次重启系统时预先选定。写访问要求待调整的参数位于RAM内。XCP的用户需要知道测量和调整值在内存中的确切地址。该地址可以通过控制单元说明文件（A2L文件）获得。XCP的一大优势是它能够从与控制单元内的程序或事件同步变化的内存上获取测量数据，从而使用户能够识别控制单元中的时间次序与这些变化值之间的直接关联，这被称为事件同步测量。

## **4 XCP协议数据结构**

主、从设备之间每次传输的数据都采用XCP帧的格式，包含一个XCP报头、XCP数据包和XCP报尾。XCP帧支持的传输层可将这三个帧元素映射到相应的传输帧格式。

![img](https://img-blog.csdnimg.cn/img_convert/9c487b6cb9dcd141a6e02d2238e7e678.png)

XCP数据包包含独立于所选传输机制的协议数据，携带标识、时间戳和实际数据。PID是标识字段的一部分，用于标记数据包及数据包内部的数据值。

![img](https://img-blog.csdnimg.cn/img_convert/a8f5fcda508ea6180a3b2b934383090d.png)

基于以太网的XCP既可以使用TCP也可以使用UDP。这两种结合方式各有优缺点。选择使用哪一种可根据使用场景决定。例如，如果要记录完整的跟踪数据，需要接收来自网络的每一个帧数据，若是在传输过程中有任何丢失，则必须重传，并保证其顺序正确如初。这种场景下必须使用TCP。与此相反，在对设备进行实时测量时，它的信号数据仅在获得下一个样本时才有效。如果测得的数据在传输过程中丢失，但下一个样本证实丢失的数据无效，那么就没有必要重传先前的报文，这种场景使用UDP即可。

XCP报头包含长度信息和一个可用于检测数据包丢失情况的计数器。主设备每发送一个数据包，就将计数器的值増加一，从设备的做法也是如此。两个计数器相互独立。多个XCP数据包可以合并到同一个UDP数据包中，但一个XCP数据包不可以分成多个数据包。UDP和TCP的XCP报尾为空。

## **5 ECU说明文件和数据记录文件**

XCP使用时总是与ECU说明文件配合使用，这个文件就是ASAP2（A2L）文件。该文件包含使用XCP所需的必要信息，包括关于ECU参数、内存变量和ECU内存详细地址信息以及如何解锁访问XCP功能的安全信息。XCP还可以从ECU上传数据，向ECU下载数据以及对ECU重新编程。为了实现这些功能，XCP Master必须知晓ECU不同内存区的详细信息。

A2L是基于ECU软件生成的，ECU软件的对象包含在A2L文件中，源代码更改后A2L文件也会进行更改。A2L文件的结构如下图。

## 

标定数据记录文件使用MDF格式，全称（Measurement Data Format），即测量数据格式，是ASAM（自动化及测量系统标准协会）定义的。INCA、CANape等工具录制的测量数据，都是MDF格式。

1991年发布的第一个公开版本是MDF 2.0（.dat）；MDF 3.0（.mdf）于2002年发布，多年来，逐步扩展。当前的非ASAM版本MDF 3.3仍完全向后兼容所有MDF 2.x和3.x版本。但是，由于文件内部链接使用32位数据类型，因此专有MDF 3.x格式的文件大小限制为4GB。

2009年发布了ASAM MDF 4.0（.mf4），克服了先前MDF3.x版本的大小限制，并提供了一系列新功能，例如通过XML的灵活可扩展性，自定义信号分组，事件或附件。但是，由于诸如链接的64位数据类型之类的根本更改，MDF 4.x不再与MDF 3.x 兼容。当前最新版本为2012年ASAM MDF 4.1。

------

CCP与XCP的用途

XCP/CCP主要应用于控制系统的开发和测试；XCP/CCP使用者为control system或mechanical engineers；XCP/CCP也广泛应用于system verification和testing



如果不用XCP/CCP，那么在ECU的软件开发中，将非常频繁使用C-code编译器和debugger。

通过XCP/CCP协议，配合A2L文件，可以直接在软件上更改某些参数，执行器就会给相应的反馈。

例如我们以前做一个单片机板子，如果想要修改里面的程序的话，需要先修改代码，再进行编译调试，生成hex或S19文件，再将程序烧写进单片机中，才算完成程序的修改。但是对于复杂的ECU来说，标定时是需要经常修改各种参数的，如果每次修改参数都需要编译调试生成再下载这一系列步骤的话，是非常影响工作效率的，所以使用CCP和XCP进行标定是非常便捷的。



CCP与XCP的优点

1、当ECU运行的时候，可以实时记录ECU内存中的变量。

2、可以具有真实物理意义和单位的数值来直接读写ECU变量，比如RPM、温度、开关等，而不是以原始的字节、位来读取。

3、实时改变ECU内存中的变量值，测试中实时改变ECU行为和性能，而不需重新编译ECU程序。

4、标定过程中，数据记录功能可以获取和记录全面的数据。

**一、CCP的介绍**

CCP主要功能

CCP全称CAN Calibration Protocol（CAN标定协议），是ASAM标准的组成部分，属于ASAM MCD1a规范标准。

CCP协议主要可提供以下功能：

1、随机读取ECU中RAM和ROM数据

2、测量数据采样

3、标定数据采样和传输

4、同时处理多个ECU系统

5、F1ash编程技术