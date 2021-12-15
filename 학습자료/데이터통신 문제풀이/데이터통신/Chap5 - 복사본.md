### 예제

#### Example 5.1) An analog signal carries 4 bits per signal element. If 1000 signal elements are sent per second, find the bit rate.

4Kbps

#### Example 5.2) An analog signal has a bit rate of 8000 bps and a baud rate of 1000 baud. A.How many data elements are carried by each signal element? B.How many signal elements do we need?

##### A) 8bits

##### B) 256

#### Example 5.3) We have an available bandwidth of 100 kHz which spans from 200 to 300 kHz. What are the carrier frequency and the bit rate if we modulated our data by using ASK with d = 1?

##### A) carrier frequency : 250Hz

##### B) bit rate : 50Kbps

> B = (1+d)N * 1/r
>
> B: BandWidth
>
> d: Transmission factor
>
> N: bit rate
>
> r: Signal element

#### Example 5.5) We have an available bandwidth of 100 kHz which spans from 200 to 300 kHz. What should be the carrier frequency and the bit rate if we modulated our data by using FSK with d = 1?

##### A) carrier frequency : 250Hz

##### B) bit rate : 25Hz

> FSK 형태
>
> ![image-20211204130419034](C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211204130419034.png)

#### Example 5.6) We need to send data 3 bits at a time at a bit rate of 3 Mbps. The carrier frequency is 10 MHz. Calculate the number of levels (different frequencies), the baud rate, and the bandwidth.
A) number of levels : 8

B)  S = 3MHz/3 = 1Mbaud/s

C) 8가지의 신호를 표시해야하고 초당 1M baud 만큼 패킷을 보내야한다. 따라서 필요한 Bandwidth는 B = 8MHz이다.

> Multilevel FSK에서 B = L * Sㅇ이다.

### 퀴즈

#### Q5-1. Define analog transmission.

##### Bandpasschannel을 이용해 아날로그 신호를 전송하는 것

#### Q5-2. Define carrier signal and explain its role in analog transmission.

##### 정보전달을 위해 입력 신호를 변조한 전자기파, 전파 전송을 위해 signal에 따라 물리적 특성이 변조된다.

#### Q5-3. Define digital-to-analog conversion.

##### 디지털신호를 정보 전송을 위해 아날로그 형태의 전자기파로 변환하는것

#### Q5-4. Which characteristics of an analog signal are changed to represent the digital signal in each of the following digital-to-analog conversions?
##### Amplitude, Phase, Frequency

#### Q5-5. Which of the four digital-to-analog conversion techniques (ASK, FSK, PSK or QAM) is the most susceptible to noise? Defend your answer.
##### ASK: Amplitude는 Frequency와 Phase에 비해 noise에 취약하다.

#### Q5-6. Define constellation diagram and explain its role in analog transmission.

##### Constellation Disagram은 signal element의 Amplitude와 phase를 정의하는 데 도움을 준다.

#### Q5-7. What are the two components of a signal when the signal is represented on a constellation diagram? Which component is shown on the horizontal axis? Which is shown on the vertical axis?

##### A) Amplitude, Phase

##### B) Inphase carrier으로의 성분

##### C) Quardrature carrier으로의 성분

#### Q5-8. Define analog-to-analog conversion.

##### 아날로그 신호를 주어진 Bandwidth내에서 전송해야할 정보를 보낼수 있도록 변환하는 과정

#### Q5-9. Which characteristics of an analog signal are changed to represent the lowpass analog signal in each of the following analog-to-analog conversions?

##### A) Amplitude

##### B) Frequency

##### C) Phase

#### Q5-10. Which of the three analog-to-analog conversion techniques (AM, FM, or PM) is the most susceptible to noise? Defend your answer.
##### AM, Amplitude가 noise에 가장 취약하다.

### 연습문제

#### P5-1. Calculate the baud rate for the given bit rate and type of modulation.
##### a. 2000 bps, FSK : 2000baud/s
##### b. 4000 bps, ASK : 4000baud/s
##### c. 6000 bps, QPSK : 3000baud/s
##### d. 36,000 bps, 64-QAM : 6000baud/s

#### P5-2. Calculate the bit rate for the given baud rate and type of modulation.
##### a. 1000 baud, FSK : 1000bps
##### b. 1000 baud, ASK : 1000bps
##### c. 1000 baud, BPSK : 1000bps
##### d. 1000 baud, 16-QAM : 4000bps

#### P5-3. What is the number of bits per baud for the following techniques?
##### a. ASK with four different amplitudes = 2bit
##### b. FSK with eight different frequencies = 3bit
##### c. PSK with four different phases = 2bit
##### d. QAM with a constellation of 128 points = 7bit

#### P5-4. Draw the constellation diagram for the following:
##### a. ASK, with peak amplitude values of 1 and 3 : 

<img src="C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211204173304932.png" alt="image-20211204173304932" style="zoom:25%;" />

##### b. BPSK, with a peak amplitude value of 2

<img src="C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211204173352011.png" alt="image-20211204173352011" style="zoom:25%;" />

##### c. QPSK, with a peak amplitude value of 3

<img src="C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211204173432745.png" alt="image-20211204173432745" style="zoom:25%;" />

##### d. 8-QAM with two different peak amplitude values, 1 and 3, and four different phases
<img src="C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211204173601917.png" alt="image-20211204173601917" style="zoom:25%;" />

#### P5-5. Draw the constellation diagram for the following cases. Find the peak amplitude value for each case and define the type of modulation (ASK, FSK, PSK, or QAM).The numbers in parentheses define the values of I and Q respectively.

##### a. Two points at (2, 0) and (3, 0) : 3 / ASK

##### b. Two points at (3, 0) and (−3, 0) : 3 / PSK
c. Four points at (2, 2), (−2, 2), (−2, −2), and (2, −2) : 2 / QAM
d. Two points at (0, 2) and (0, −2) : 2 / PSK

#### P5-6. How many bits per baud can we send in each of the following cases if the signal constellation has one of the following number of points?
##### A) 2 : 1bit

##### B) 4 : 2bit

##### C) 16 : 4bit

##### D) 1024 : 10bit

#### P5-7. What is the required bandwidth for the following cases if we need to send 4000 bps? Let d = 1.
##### a. ASK : B = (1+d)S => 2S = 8000Hz

##### b. FSK with 2"f = 4 KHz : B = (1+d)S +2df => 2S+4KHz = 12KHz

##### c. QPSK : B = (1 + d)S => 2S = 4KHz

##### d. 16-QAM : B = (1+d)S => 2 * 1KHz = 2KHz

#### P5-8. The telephone line has 4 KHz bandwidth. What is the maximum number of bits we can send using each of the following techniques? Let d = 0.

##### A) ASK : S = N  => 4000bits

##### B) QPSK : B = 1*(N * 1/2) => N = 2B => 8000bits 

##### C) 16-QAM : B = 1*(N * 1/4) => N = 4B => 16000bits 

##### D) 64-QAM : B = 1*(N * 1/6) => N = 6B => 24000bits 

#### P5-9. A corporation has a medium with a 1-MHz bandwidth (lowpass). The corporation needs to create 10 separate independent channels each capable of sending at least 10 Mbps. The company has decided to use QAM technology. What is the minimum number of bits per baud for each channel? What is the number of points in the constellation diagram for each channel? Let d = 0.

##### A) 10bits

##### B) 1024 points

> B = (1+d)N
>
> B = Bandwidth (Hz)
>
> d = communication factor
>
> N = S * 1/Log2(L) : (baud/s)
>
> S = bit rate (bps)
>
> L = level (int)
>
>  1MHz = 1*(1000M * 1/r) => r = 1000 => log2(L) = 1000 => L = 10

#### P5-10. A cable company uses one of the cable TV channels (with a bandwidth of 6 MHz) to provide digital communication for each resident. What is the available data rate for each resident if the company uses a 64-QAM technique?
##### A) 6MHz = 1*(S * 1/6) => S = 36Mbps

> 별도의 언급이 없을경우 d = 0이다

#### P5-11. Find the bandwidth for the following situations if we need to modulate a 5-KHz voice.

##### A) AM : 10KHz

##### B) FM(b = 5) : 12*5 = 60KHz

##### C) PM (b = 1) : 4*5 = 20KHz

> Modulation Band Width
>
> AM: B = 2B
>
> FM: B = 2(1+b)B
>
> PM: B = 2(1+b)B
>
> b: factor of modulation techqunic
