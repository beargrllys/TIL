Byte stuffing / Bit stuffing

Flow control(패킷을 어떻게 보낼것인가) => Simplest / Stop and wait in noisless channel

Stop and wait ARQ / Go Back N ARQ/ selective Repeat ARQ in noisy channel

Go Back N ARQ : Sender Window Size가 2^m -1

selective Repeat ARQ : Sender Window Size가 2^(m -1)

#### 퀴즈

#### Q11-1. Define framing and give the reason it is needed.

Frame이 매우 크면 데이터를 전송할때 1bit만 잘못 보내져도 대량의 데이터를 다시보내야하기 때문에 재전송 시에도 부담이 없는 작은 단위로 나눈것이 frame이다.

#### Q11-2. Explain why flags are needed when we use variable-size frames.

전송시에는 frame들이 연속으로 붙어 있는 bit들의 흐름으로 들어오는데이때 frame의 시작과 끝을 알기 위해서 사용한다. 

#### Q11-3. Assume a new character-oriented protocol is using the 16-bit Unicode as the character set. What should the size of the flag be in this protocol?
character Oriented protocol에서 flag는 frame의 시작과 끝을 표현하는 단위로 16bit unicode 치계에서 flag는 16bit이어야 한다.

#### Q11-4. Compare and contrast byte-oriented and bit-oriented protocols.

byte oriented와 bit oriented는 framing시에 감싸지는 단위를 말한다. 

#### Q11-5. Compare and contrast byte-stuffing and bit-stuffing.

btye stuffing은 전송시 flag와 오해될수 있는 character앞에 ESC char를 붙혀 stuffing될수 있도록 한것이고 bit stuffing은 flag 특유의 패턴이 데이터에 섞여 오해되기를 방지하기위해 대표적으로 연속되는 1이 등장하지 않도록 처리하고 전송하는 방식이다.

#### Q11-6. In a byte-oriented protocol, should we first unstuff the extra bytes and then remove the flags or reverse the process?
정식 flag가 먼저 제거되고 data 부분만 추출된 곳에서 unstuff될것이다.

#### Q11-7. In a bit-oriented protocol, should we first unstuff the extra bits and then remove the flags or reverse the process?

정식 flag가 먼저 제거되고 data 부분만 추출된 곳에서 unstuff될것이다.

#### Q11-8. Compare and contrast flow control and error control.

flow control은 데이터가 전송되기위한 일련의 frame들을 정상적으로 보내기 위함이고 error control은 전송시 Data가 error없이 온전히 보내기 위한 기법들이다.  

#### Q11-9. In the Stop-and-Wait Protocol, assume that the sender has only one slot in which to keep the frame to send or the copy of the sent frame. What happens if the network layer delivers a packet to the data-link layer at this moment?
이전에 보냈전 frame에 대한 Ack가 돌아올때까지 대기했다가 Ack가 오는데로 전송을 한다.

#### Q11-10. In Example 11.3 (Figure 11.12) how many frames are in transit at the same time?
1개

#### Q11-11. In Example 11.4 (Figure 11.13) how many frames are in transit at the same time?
1개

#### 연습문제

#### P11-1. Byte-stuff the following frame payload in which E is the escape byte, F is the flag byte, and D is a data byte other than an escape or a flag character.
D E E D D E F D D E E E E D E F D

#### P11-2. Unstuff the following frame payload in which E is the escape byte, F is the flag byte, and D is a data byte other than an escape or a flag character.
![image-20211210143926178](C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211210143926178.png)

EDFDDFEDDD

#### P11-3. Bit-stuff the following frame payload:

#### 0001111111001111101000111111111110000111

00011111011001111100100011111011111010000111

#### P11-4. Unstuff the following frame payload:

#### 00011111000001111101110100111011111000001111

00011111000011111111010011101111100001111

#### P11-5. Assume we change the Stop-and-Wait Protocol to include a NAK (negative feedback), which is used only when a corrupted frame arrives and is discarded. Redraw Figure 11.9 to show this change.
![image-20211210144417906](C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211210144417906.png)

#### P11-6. In Example 11.4 (Figure 11.13), assume the round trip time for a frame is 40 milliseconds. Explain what will happen if we set the time-out in each of the
following cases.
![image-20211210144550757](C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211210144550757.png)

#### a. 35 milliseconds 

정상적인 상황에서도 아직 ACK가 물리적으로 도착하지 않았음에도 Sender에서 재전송을 해버려 첫번째 feame만 계속 보내게된다.  

#### b. 45 milliseconds 

정상적으로 전송이 진행된다.

#### c. 40 milliseconds

약간만 delay가 있어도 재전송을 시도해버린다.

#### P11-7. Redraw Figure 11.12 using the following scenario:

>a. The first frame is sent and acknowledged.
>b. The second frame is sent and acknowledged, but the acknowledgment is
>lost.
>c. The second frame is resent, but it is timed-out.
>d. The second frame is resent and acknowledged.

<img src="C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211210150431750.png" alt="image-20211210150431750" style="zoom: 50%;" />

#### P11-8. Redraw Figure 11.12 using the following scenario:

> a. Frame 0 is sent, but lost.
> b. Frame 0 is resent and acknowledged.
> c. Frame 1 is sent and acknowledged, but the acknowledgment is lost.
> d. Frame 1 is resent and acknowledged.

<img src="C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211210150900048.png" alt="image-20211210150900048" style="zoom:50%;" />

![image-20211210144601392](C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211210144601392.png)

![image-20211210144616142](C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211210144616142.png)

#### P11-9. In Figure 11.11, show what happens in each of the following cases:
#### a. The sender is at the ready state and an error-free ACK arrives.

현재 ACK 대기중이던 frame을 폐기하고 Timer를 초기화한다.

#### b. The sender is at the blocking state and a time-out occurs.

현재 ACK 대기중인 Frame을 재전송하고  Timer를 초기화한다.

#### c. The sender is at the ready state and a time-out occurs.

Blocking State로 이동해 Time Out Event를 발생 시킨다.

#### P11-10. In Figure 11.11, show what happens in each of the following cases:
#### a. The receiver is in the ready state and a packet comes from the network layer.

도착시 frame을 Network layer에 전달하거나 폐기합니다.

#### b. The receiver is in the ready state and a corrupted frame arrives.

frame을 폐기하고 재전송 frame을 대기한다..

#### c. The receiver is in the ready state and an acknowledgment arrives.

수진자는 ACK를 받을수 없습니다.