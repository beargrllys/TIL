> Data Link layer의 주요한 기능
>
> 1. Framing : A packet at the data-link layer is normally called a frame.
> 2. Flow control : If the rate of produced frames is higher than the rate of consumed frames, frames at the receiving end need to be buffered while waiting to be consumed (processed).
> 3. Error Control : At the sending node, a frame in a data-link layer needs to be changed to bits, transformed to electromagnetic signals, and transmitted through the transmission media.
> 4. Congestion Control : Although a link may be congested with frames, which may result in frame loss, most data-link-layer protocols do not directly use a congestion control to alleviate congestion,

> Link의 종류
>
> 1. point to point link : the link is dedicated to the two devices
> 2. broadcast link : shared between several pairs of devices.

> Address Resolution Protocol(ARP)
>
> 목적지의 IP address는 알지만, MAC address를 모를 때 Target MAC address 부분을 00:00:00:00:00:00으로 채우고
> 패킷의 목적지를 broadcast(ff:ff:ff:ff:ff:ff) 로 하여 네트워크 상의 모든 노드들한테 뿌려서
> Target MAC address를 얻어오는 것을 ARP protocol이 하는 일 입니다

### 퀴즈

#### Q9-1. Distinguish between communication at the network layer and communication at the data-link layer.

##### Network layer is communication with IP Address with end to end Communication. Data-link layer is node to node communication with MAC Address

#### Q9-2. Distinguish between a point-to-point link and a broadcast link.
##### point to point link is the link that have destination address. Broadcast link has none destination address. So it receive the packet to every connected device. 

#### Q9-3. Can two hosts in two different networks have the same link-layer address? Explain.

##### 서로다른 네트워크에서 같은 MAC Address를 가질수 있긴하다. 하지만 추후 문제가 생길수도 있다.

#### Q9-4. Is the size of the ARP packet fixed? Explain.

##### 2개의 Destination Address와 Protocol Address가 있기 때문에 크기가 정해져있지 않다. Network layer와 Data link layer에서 packet을 다루면서 크기가 유동적으로 변한다.

#### Q9-5. What is the size of an ARP packet when the protocol is IPv4 and the hardware is Ethernet?
##### 목적지 주소는 End to End의 주소를 정의하고 있다.

> Hardware Type : 16bits
>
> Protocol Type : 16bits
>
> Hardware Length : 8bits
>
> Protocol Length : 8bits
>
> Operation : 16bits
>
> Source MAC : 48bits
>
> Source Protocol addr : 32bit
>
> Destination MAC : 48bits
>
> Destination Protocol addr : 32bit
>
> 2+2+1+1+2+6+4+6+4 = 28byte

####  Q9-6. Assume we have an isolated link (not connected to any other link) such as a private network in a company. Do we still need addresses in both the network layer and the data-link layer? Explain.

##### 단일 네트워크이더라도 Link layer network는 device-device간의 통신에 필요하기 때문에 필요하다. Network Layer의 경우 Data-link Layer으로만 통신이 가능하다면 필요없겠지만 Rounting이나 Packet Switching과정이 필요로한다면 Network layer의 IP Addrress가 반드시 필요하다.

#### Q9-7. In Figure 9.9, why is the destination hardware address all 0s in the ARP request message?

##### Destination Device의 physical address를 몰라서 broadcast message로 System B의 physical address를 획득하기 위해 요청한것이다.

#### Q9-8. In Figure 9.9, why is the destination hardware address of the frame from A to B a broadcast address?

##### Destination Address를 알지 못해서  모두 0인 상태로 전송하면 Netowork에 연결된 모든 노드들이 해당 ARP Packet을 받게되기 때문에 broadcast address가 된다.

#### Q9-9. Compare and contrast the two major categories of circuit switches.

##### Space Division Switch는 요청 즉시 연결되는 대신 연결된 기기의 대수만큼 Cross Point를 필요로한다. Time Division Switch는 Cross point가 필요치 않은 대신 모든 Connection에 Delay가 발생한다.

#### Q9-10. When we talkabout the broadcast address in a link, do we mean sending a message to all hosts and routers in the link or to all hosts and routers in the Internet? In other words, does a broadcast address have a local jurisdiction or a universal jurisdiction? Explain.

#####  Yes, but They are not accept that all received broadcast address packet if the message's network layer address is not matched. 

#### Q9-11. Why does a host or a router need to run the ARP program all of the time in the
background?

#####  We do not know when another host tries to request your physical address.

#### Q9-12. Why does a router normally have more than one interface?

##### Router must take a request to many hosts stimulate, and process their packet to another.

#### Q9-13. Why is it better not to change an end-to-end address from the source to the destination?

##### If the end to end address is changed, It can not ensure that the data packet is delivered.

#### Q9-14. How many IP addresses and how many link-layer addresses should a router have when it is connected to five links?

##### 10 (5 for end host, 5 for Router)

### 연습문제

#### P9-1. Assume we have an internet (a private small internet) in which all hosts are connected in a mesh topology. Do we need routers in this internet? Explain.

##### No, They are all connected between device.

#### P9-2. In the previous problem, do we need both network and data-link layers?

##### 노드간 통신에 Network layer가 필요하진 않는다. 그리고 다른 디바이스로 건너뛰려면 data link layer은 필요할것이다. 하지만 통신 내부적으로 TCP/IP suite를 사용한다면 규정된 규칙에 따라 두 layer이 모두 필요할것이다.

#### P9-3. Explain why we do not need the router in Figure 9.15.

##### ![image-20211208174057968](image-20211208174057968.png)

##### 라우터를 거치지 않아도 두 노드 끼리 직접적으로 통신할수 있다.

#### P9-4. Explain why we may need the router in Figure 9.16.

![image-20211208174702432](image-20211208174702432.png)

##### node 간의 통신이 modem을 통해 연결되고 있기 때문이다.

#### P9-5. Is the current Internet using circuit-switching or packet-switching at the datalink layer? Explain.
##### Packet switching을 사용한다. 소스는 frame 단위로 나뉘어 독립적으로 움직인다.

#### P9-6. Assume Alice is travelling from 2020 Main Street in Los Angeles to 1432 American Boulevard in Chicago. If she is travelling by air from Los Angeles Airport to Chicago Airport,
##### a. find the end-to-end addresses in this scenario.

##### Source address : 1432 American Boulevard

##### Destination address : 2020 Main street

##### b. find the link-layer addresses in this scenario.

##### Source address :  1432 American Boulevard

##### Destination address : 2020 Main street

#### P9-7. In the previous problem, assume Alice cannot find a direct flight from the Los Angeles to the Chicago. If she needs to change flights in Denver,
##### a. find the end-to-end addresses in this scenario.

##### Source address : 1432 American Boulevard

##### Destination address : 2020 Main street

##### b. find the link-layer addresses in this scenario.

##### 2020 Main Street => Los Angeles Airport => Denver => Chicago Airport => 1432 American Boulevard

#### P9-8. When we send a letter using the services provided by the post office, do we use an end-to-end address? Does the post office necessarily use an end-to-end address to deliver the mail? Explain.
##### 우리가 편지에 작성하는 주소는 End to end address이다. 하지만 우편 시스템에서는 End point로 가기위해 다수의 기착지를 거쳐가기 때문에 실질적으로 배달 되는것은 말단을 제외하고는 link layer address를 사용한다고 할수 있다.

#### P9-9. In Figure 9.5, assume Link 2 is broken. How can Alice communicate with Bob?

![image-20211208194826580](image-20211208194826580.png)

##### 통신이 불가능하다.

#### P9-10. In Figure 9.5, show the process of frame change in routers R1 and R2.

#### R1

##### Before : income port : L1 / Outgoing port : L2 

##### After : income port : L4 / Outgoing port : L5 

##### L2 | L1 | N1 | N8 => L5 | L4 | N1 | N8

#### R2

##### Before : income port : L4 / Outgoing port : L5 

##### After : income port : L7 / Outgoing port : L8 

##### L5 | L4 | N1 | N8 => L8 | L7 | N1 | N8

#### P9-11. In Figure 9.7, assume system B is not running the ARP program. What would happen?
##### system A에서 상대의 Physical address를 알수 없게 되어 broadcast packet을 계속 보내 네트워크에 불필요한 부하가 가해지고  setup phase가 진행되지 않는다.

#### P9-12. In Figure 9.7, do you think that system A should first check its cache for mapping from N2 to L2 before even broadcasting the ARP request?
![image-20211208202243660](image-20211208202243660.png)

##### ARP request를 Broadcast하기 이전에 N2 연결에 대한 Cache가 존재한다면 우선적으로 체크하여야 네트워크 성능에 도움이된다. 

#### P9-13. Assume the network in Figure 9.7 does not support broadcasting. What do you suggest for sending the ARP request in this network?
##### Broadcasting이 지원하지 않는다면 다른 노드의 MAC Address를 알수 없기 때문에 해당네트워크에 연결되어있는 다른 모든 노드의 MAC Address를 수집한 Cache를 수집하면  point to point link message로 전송이 가능하다.



#### P9-14. In Figures 9.11 to 9.13, both the forwarding table and ARP are doing a kind of mapping. Show the difference between them by listing the input and output of mapping for a forwarding table and ARP.
Dest Phy | Sour Phy | Sour IP | Dest IP | Data

##### Alice Site

Input : Na | Nb |  Data

Output : L1 | La | Na | Nb |  Data

##### R1

Input : L1 | La | Na | Nb |  Data

Output : L3 | L2 | Na | Nb |  Data

##### R2

Input : L3 | L2 | Na | Nb |  Data

Output : Lb | L4 | Na | Nb |  Data



#### P9-15. Figure 9.7 shows a system as either a host or a router. What would be the actual entity (host or router) of system A and B in each of the following cases:
#### a. If the link is the first one in the path?

link가 처음이라면 두 시스템 모두 host일수밖에 없다. 

#### b. If the link is the middle one in the path?

link가 시스템의 중간에 있다면 A,B는 router일수 밖에 없다

#### c. If the link is the last one in the path?

link가 시스템의 종단에 있다면 host일수도 router일수도있가.

#### d. If there is only one link in the path (local communication)?

host이어야만한다.
