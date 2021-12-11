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

#### P8-3. Transmission of information in any network involves end-to-end addressing and sometimes local addressing (such as VCI). Table 8.2 shows the types of networks and the addressing mechanism used in each of them.

![image-20211208122210410](.\image\image-20211208122210410.png)

##### a. Why does a circuit-switched network need end-to-end addressing during the setup and teardown phases? Why are no addresses needed during the data transfer phase for this type of network?

Circuit Switch Network의 경우 dedicated 통신을 하기때문에 Setup phase와 Teardown phase에만 address 를 명시해주면 data tranfer phase에는 해당화선을 사용하는것이 setup되어진 통신 밖에 업기때문에 end to end address를 명시해줄필요가 없다. 

##### b. Why does a datagram network need only end-to-end addressing during the data transfer phase, but no addressing during the setup and teardown phases?

Datagram Network에서는 데이터를 전송하기만하고 Packet이 독립적으로 움직인다. Packet loss나 packet check를 하지않기 때문에 별도의 setup, teardown 과정없이 Data transfer과정에서만 end to end address를 명시하고 전송한다. 

##### c. Why does a virtual-circuit network need addresses during all three phases?

virtual-circuit network는 setup과 Teardown 과정에서 destination과 해당 통신을 위한 Routing table를 만들기 위해 end to end address를 명시하고 Datatranfer과정에서 순서대로 destination에 도착해야하기때문에  VCI를 통해 같은 hop으로 보내지기 위해 Local address를 표기한다.   

#### P8-4. We mentioned that two types of networks, datagram and virtual-circuit, need a routing or switching table to find the output port from which the information belonging to a destination should be sent out, but a circuit-switched network has no need for such a table. Give the reason for this difference.
Circuit switch는 source과 destination이 Packetized되지 않고 직접적으로 연결되어 있어서 datagram이나 virtual circuitswitch와는 달리 별도의 switch table를 만들지 않아도 된다.

#### P8-5. An entry in the switching table of a virtual-circuit network is normally created during the setup phase and deleted during the teardown phase. In other words, the entries in this type of network reflect the current connections, the activity in the network. In contrast, the entries in a routing table of a datagram network do not depend on the current connections; they show the configuration of the network and how any packet should be routed to a final destination. The entries may remain the same even if there is no activity in the network. The routing tables, however, are updated if there are changes in the network. Can you explain the reason for these two different characteristics? Can we say that a virtual-circuit is a connection-oriented network and a datagram network is a connectionless network because of the above characteristics?
virtual-circuit network는 setup phase와 Teardown phase에서 통신 연결을 수립하기 때문에 Connectio-Oriented라고 부르고 datagram network은 통신의 연결여부와 상관없이 End to End address를 보고 switch되어기지 때문에 Connectionless 특성을 가지고 있다고 할수 있다.

#### P8-6. The minimum number of columns in a datagram network is two; the minimum number of columns in a virtual-circuit network is four. Can you explain the reason? Is the difference related to the type of addresses carried in the packets of each network? 
Datagram Network에서는 Destination port와 Output Port가 있고 virtual-circuit network is four에서는 Incoming Port와 VCI / Outgoing Port와 VCI로 Column이 이루어져있다.  패킷이 다음으로 어디에 switch될지를 보여주는것이다.

####  P8-7. Figure 8.27 shows a switch (router) in a datagram network.

![image-20211208132414226](.\image\image-20211208132414226.png)

#### Find the output port for packets with the following destination addresses:

##### a. Packet 1: 7176 => Port2

##### b. Packet 2: 1233 => Port3
##### c. Packet 3: 8766  => Port3

##### d. Packet 4: 9144 => Port2

#### P8-8. Figure 8.28 shows a switch in a virtual-circuit network.

![image-20211208132748784](.\image\image-20211208132748784.png)

##### Find the output port and the output VCI for packets with the following input port and input VCI addresses:
##### a. Packet 1: 3, 78 => 2,70

##### b. Packet 2: 2, 92 => 1,45
##### c. Packet 3: 4, 56  => 3,11

##### d. Packet 4: 2, 71 => 4,41

#### P8-9. Answer the following questions:
##### a. Can a routing table in a datagram network have two entries with the same destination address? Explain.

##### Destination address은 Datagram network에서는 유일하기 때문에 Rounting table에서 중복될수 없다.

##### b. Can a switching table in a virtual-circuit network have two entries with the same input port number? With the same output port number? With the same incoming VCIs? With the same outgoing VCIs? With the same incoming values (port, VCI)? With the same outgoing values (port, VCI)?

VCI는 switch간에 관계를 유일하게 표현한것이기 때문에  특정포트과 VCI의 조합은 유일하다. 

#### P8-10. It is obvious that a router or a switch needs to search to find information in the corresponding table. The searching in a routing table for a datagram network is based on the destination address; the searching in a switching table in a virtual-circuit network is based on the combination of incoming port and
incoming VCI. Explain the reason and define how these tables must be ordered (sorted) based on these values.

Datagram netowrk는 destination address 기반으로 정렬되어있고 Virtual cirsut switch에서는 Incoming port와 incoming VCI를 기반으로 정렬되어있다. 이렇게 정렬이 되어있어야 input 에 대한 outgoing을 찾기 편하기때문에 이렇게 정려되어있는것이다.

