### 퀴즈

#### Q6-1. Describe the goals of multiplexing.(p221)

##### 복수의 신호들이 한개의 데이터링크를 통해 동시에 전송되도록하기 위한것이다.

#### Q6-2. List three main multiplexing techniques mentioned in this chapter.

##### Frequency-Division Multiplexing, Wavelength-Division Multiplexing, Time-Division Multiplexing 

#### Q6-3. Distinguish between a link and a channel in multiplexing.

##### Link는 두 노드를 이어주는 물리적경로를, Channel은 두 회선사이에서 전송 진행하는 link의 일부라고 한다.

#### Q6-4. Which of the three multiplexing techniques is (are) used to combine analog signals? Which of the three multiplexing techniques is (are) used to combine digital signals?
##### FDM과 WDM이 아날로그 신호의 Multiplexing에 사용되고 TDM이 디지털 신호의 Multiplexing에 사용된다.

#### Q6-5. Define the analog hierarchy used by telephone companies and list different levels of the hierarchy.

![image-20211203181622325](C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211203181622325.png)

#### Q6-7. Which of the three multiplexing techniques is common for fiber-optic links? Explain the reason.

##### WDM

#### Q6-8. Distinguish between multilevel TDM, multiple-slot TDM, and pulse-stuffed TDM.
##### multilevel TDM: Input line에 들어오는 신호를 합쳐서 다른 MUX의 입력신호로 입력하는 기술

##### multiple-slot TDM : Input line에 들어오는 신호를 분해해서 다른 MUX의 입력신호로 입력하는 기술

##### pulse-stuffed TDM: 다른 입력값비해 적은 입력값에 Dummy bit를 보충하여 bit의 배수를 맞춰주는 기술

#### Q6-9. Distinguish between synchronous and statistical TDM.

##### synchronous TDM : 모든 입력값에 Time slot을 할당하여 동기화된 속도로 Multiplexing된 데이터를 전송하는 TDM

##### statistical TDM : 실제 입력값이 들어오는 데이터만들 추려서 address을 붙히고 Multiplexing을 수행하는 TDM

### 연습문제

#### P6-1. Assume that a voice channel occupies a bandwidth of 4 kHz. We need to multiplex 10 voice channels with guard bands of 500 Hz using FDM. Calculate the required bandwidth.

##### 4KHz * 10  + (500 * 9) = 44500Hz

 #### P6-2. We need to transmit 100 digitized voice channels using a passband channel of 20 KHz. What should be the ratio of bits/Hz if we use no guard band?

##### 5bit/Hz

#### P6-4. We need to use synchronous TDM and combine 20 digital sources, each of 100 Kbps. Each output slot carries 1 bit from each digital source, but one extra bit is added to each frame for synchronization. Answer the following questions:

##### a. What is the size of an output frame in bits? : 21bit
b. What is the output frame rate? : 100k frames/s
c. What is the duration of an output frame? : 10us
d. What is the output data rate? : 2.1Mbps
e. What is the efficiency of the system (ratio of useful bits to the total bits)? 95%

#### P6-5. Repeat Problem 6-4 if each output slot carries 2 bits from each source.

##### a. What is the size of an output frame in bits? : 41bit
b. What is the output frame rate? : 100k frames/s
c. What is the duration of an output frame? : 10us
d. What is the output data rate? : 4.1Mbps
e. What is the efficiency of the system (ratio of useful bits to the total bits)? 97%

#### P6-6. We have 14 sources, each creating 500 8-bit characters per second. Since only some of these sources are active at any moment, we use statistical TDM to combine these sources using character interleaving. Each frame carries 6 slots at a time, but we need to add 4-bit addresses to each slot. Answer the following questions:

##### a. What is the size of an output frame in bits? : 72bit

##### b. What is the output frame rate? : 6slot => 6 inputline : 500 frames/s

##### c. What is the duration of an output frame? : 2ms

##### d. What is the output data rate? : 36kbps

> statistical TDM에서 Slot은 address와 data를 모두 포함한다. 

#### P6-7. Ten sources, six with a bit rate of 200 kbps and four with a bit rate of 400 kbps, are to be combined using multilevel TDM with no synchronizing bits. Answer the following questions about the final stage of the multiplexing:

##### a. What is the size of a frame in bits? : 7bits

##### b. What is the frame rate? : 400k frames/s

##### c. What is the duration of a frame? : 2.5us

##### d. What is the data rate? : 2.8Mbps

> multilevel TDM에서는 별도의 언급이 없으면 input line의 개수만큼 frame당 bits가 들어간다.

#### P6-8. Four channels, two with a bit rate of 200 kbps and two with a bit rate of 150 kbps, are to be multiplexed using multiple-slot TDM with no synchronization bits. Answer the following questions:

##### a. What is the size of a frame in bits? : 14bits
##### b. What is the frame rate? : 50k frames/s
##### c. What is the duration of a frame? 20us
##### d. What is the data rate? 700kbps

#### P6-9. Two channels, one with a bit rate of 190 kbps and another with a bit rate of 180 kbps, are to be multiplexed using pulse-stuffing TDM with no synchronization bits. Answer the following questions:
##### a. What is the size of a frame in bits? : 2bit

##### b. What is the frame rate? : 190k frames/s

##### c. What is the duration of a frame? 520us

##### d. What is the data rate? 380kbps

#### Show the contents of the five output frames for a synchronous TDM multiplexer that combines four sources sending the following characters. Note that the characters are sent in the same order that they are typed. The third source is silent.
##### a. Source 1 message: HELLO

##### b. Source 2 message: HI

##### c. Source 3 message:

##### d. Source 4 message: BYE

##### |      O|      L|E    L|Y  IE|B  HH|

#### P6-12. Figure 6.34 shows a multiplexer in a synchronous TDM system. Each output slot is only 10 bits long (3 bits taken from each input plus 1 framing bit). What is the output stream? The bits arrive at the multiplexer as shown by the arrows.
##### |0    1            |1010  11101|0000111011|1100011111|0111000101

#### P6-13. Figure 6.35 shows a demultiplexer in a synchronous TDM. If the input slot is 16 bits long (no framing bits), what is the bit stream in each output? The bits arrive at the demultiplexer as shown by the arrows.

##### output1 : 0000|0001|1000

##### output2 : 1010|1010|0111

##### output3 :         |1010|0000

##### output4 :         |1010|0111



> 뒷부분은 OFDM 파트 수업안함
>
> 총 예제 11문제 퀴즈 12문제 연습문제 18문제