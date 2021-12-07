### 퀴즈

#### Q8-1. Describe the need for switching and define a switch.

##### Switch는 단일 네트워크에서 여러 기기가 연결되었을때 생기는 문제를 해결해주는 역할을 한다. 그래서 Switch는 연결된 다수의 기기들 간에 임시적인 통신을 하도록 보내주는 역할을 한다.

#### Q8-2. List the three traditional switching methods. Which are the most common today?
##### Circuit switching / Packet swtiching / message switching

#### Q8-3. What are the two approaches to packet switching?

##### Virtual circuit approach / Datagram approach

#### Q8-4. Compare and contrast a circuit-switched network and a packet-switched network.

##### Circuti switch는 Connection Setup이라는 과정을 통해 dedicated Connection을 기반으로 통신하지만 Packet Network는 별도의 Setup 과정없이 요청 될때 그때그때 할당한다.

> Circuit Switch network's Three Phase
>
> : Connection Setup => Data Transfer => Connection Teardown
>
> Packet Switch network
>
> => In a packet-switched network, there is no resource reservation; resources are allocated on demand.
>
> Datagram network's Three Phase
>
> > A switch in a datagram network uses a routing table that is based on the destination
> > address.
>
> > The destination address in the header of a packet in a datagram network
> > remains the same during the entire journey of the packet.
>
>  Virtual-Circuit Networks
>
> > In virtual-circuit switching, all packets belonging to the same source and destination travel the same path, but the packets may arrive at the destination with different delays if resource allocation is on demand.

#### Q8-5. What is the role of the address field in a packet traveling through a datagram network?
##### 목적지 주소는 End to End의 주소를 정의하고 있다.

####  Q8-6. What is the role of the address field in a packet traveling through a virtual circuit network?

##### 목적지 주소는 Virtual circuit의  Number를 정의하는 역할을 한다.

#### Q8-7. Compare space-division and time-division switches.

##### space-division Switch는 물리적으로 구성된 소자 공간내에서 경로를 분리하여 Switch하는 방식이고 time-division switches는 TDM(Time Division Multiplexing) 을 이용하여 단위 시간동안 특정 Connection만 연결되도록하는 방식이다.

> Circuit switching에는 Space division Switch와 Time division Switching으로 나뉘어진다.
>
> > Space division Switch에는 Cross Switch와 MultiSatge Switch로 나뉘어진다.
> >
> > 이를 통합한  Time and Space-Division Switch Combination도 존재한다.

#### Q8-8. What is TSI(Time slot interchange) and what is its role in time-division switching?

##### TSI는 들어오는 Time Slot의 주소값을 변경시켜 원하는 기기로 데이터가 Demultiplexing 되도록 하는 장치이다.

#### Q8-9. Compare and contrast the two major categories of circuit switches.

##### Space Division Switch는 요청 즉시 연결되는 대신 연결된 기기의 대수만큼 Cross Point를 필요로한다. Time Division Switch는 Cross point가 필요치 않은 대신 모든 Connection에 Delay가 발생한다.

#### Q8-10. List four major components of a packet switch and their functions.

#####  Input port, Output port, Rounting Processor, Switching Fabric

### 연습문제

#### P8-1. A path in a digital circuit-switched network has a data rate of 1 Mbps. The exchange of 1000 bits is required for the setup and teardown phases. The distance between two parties is 5000 km. Answer the following questions if the propagation speed is 2 × 108 m:

##### A)What is the total delay if 1000 bits of data are exchanged during the datatransfer phase?:

##### 3.025 ms

##### B)What is the total delay if 100,000 bits of data are exchanged during the data-transfer phase?

##### 102.025ms

##### C)What is the total delay if 1,000,000 bits of data are exchanged during the data-transfer phase?

##### 1.000025s

##### D)Find the delay per 1000 bits of data for each of the above cases and compare them. What can you infer?

##### 전송하는 데이터의 크기가 작을수록 Setup과 teardown을 위한 bit의 비율이 커져서 전송되는 실제 데이터의 크기가 클수록 효율적이다. 다만 데이터의 크기를 키우면 그만큼 전송에 Loss가 생겼을때 다시 전송에 드는 부담이 커진다.

#### P8-2. Five equal-size datagrams belonging to the same message leave for the destination one after another. However, they travel through different paths as shown in Table 8.1.

![image-20211205011341805](C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211205011341805.png)

##### We assume that the delay for each switch (including waiting and processing) is 3, 10, 20, 7, and 20 ms respectively. Assuming that the propagation speed is 2 × 108 m, find the order the datagrams arrive at the destination and the delay for each. Ignore any other delays in transmission.
