> Character-Oriented Framing : Character 단위로 framing 을 전송하는것
>
> => flag와 우연하게 bit가 겹쳐버리면 전송에 문제가 생김
>
> Byte stuffing : 실질 데이터 앞뒤로 ESC character을 삽입하여 실질 데이터의 시작과 끝을 표시하는것
>
> 뒤에는 frame을 해체할때  frame의 유효 데이터 앞뒤의 ESC를 삭제한다. 그리고 뒤에는 연속된 ESC를 붙힘으로서 실질 데이터 내에서도 실질 데이터의 끝을 표시하는 기법이다.
>
> > Frame of bit Oriented Protocol
> >
> > 01111110 | Header | Data | Tail | 01111110
> >
> > 1.Flag(01111110) 패턴의 중복 회피 방식 : 1이 연속 5번 나오면 무조건 0을 추가한다. (Stuffed)
> >
> > 2.Frame을 전송한다.
> >
> > 3.공식적인 Flag이후에 추가한 0을 식별하여뒤에 있는 0을 제거한다.
> >
> > =>불필요한 곳에 stuffing bit가 들어가게되지만 통신의 안정성을 위해 감안한다.
>
> => 1개의 Frame의 크기를 조절하는것

> Flow-control: 이미 만들어진 frame을 몇개씩을 보내야 Network에 무리가 생기지 않는가

> Error control : Error가 감지되면 데이터를 다시 요청하는것

> Protocol => noiseless channel(비연결 지향 프로토콜: frame간 논리적 관계X) : Simplest, Stop-and-wait
>
> ​                => noisy channel(연결 지향 프로토콜: frame간 논리적 관계O) : Stop-And-wait ARQ, Go-Back-N ARQ, Selective Repeat ARQ
>
> > Stop-And-Wait Protocol: frame을 보내고 수신측으로부터 ACK가 수신되면 다음 frame을 보낸다.
> >
> > (state Diagram 보기)
