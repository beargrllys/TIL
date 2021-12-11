### Microprocessor Interface 시험범위

#### 1. 강의 6 Design Vending Machine (자판기) [p15]

- ##### state diagram 그리기 

 ![image-20211211170606225](C:\Users\js774\AppData\Roaming\Typora\typora-user-images\image-20211211170606225.png)

####  2. 강의 6 Mealy FSM(Finity State Machine) [p16~17]

- ##### always 2개 구문 외우기 

``` verilog
	// 순차적으로 state를 정기적으로 업데이트 해준다
// posedge : 0에서 1이 되는 순간
// negedge : 1에서 0이 되는 순간
always @ (posedge clk or negedge reset) // Clock 마다, reset
    if (!reset) state <= IDLE; //reset이 0이되면 state를 IDLE로 바꿔줌
		else state <= next; //나머지의 경우에는 state를 다음으로 진행시켜줌

//state업데이트에 대한 비동기 초기화
```

``` verilog
//state Diagram 대로 코드짜기
always @ (state or N or D or Q) //무엇이 무엇이 들왔을까?
    begin
	    DC = 0; DN = 0; DD = 0; // 초기화
	    case (state)
            IDLE: //아무일없으면 다음 상황 확인 
                if (Q) 
                    next = GOT_25c; // Q=1이면 quarter가 들어온것
            	else if (D) 
                    next = GOT_10c; // D=1이면 dime이 들어온것
            	else if (N) 
                    next = GOT_5c; // N=1이면 quarter가 들어온것
                else 
                    next = IDLE; // 아니면 넌 백수임
            GOT_5c: // Nickel이 들어온 상황이다
                if (Q) 
                    begin //25센트가 들어왔으면 음료를 주고 Idle;
		         		DC = 1; next = IDLE;
		       		end
	    	    else if (D) 
                    next = GOT_15c;
		     	else if (N) 
                    next = GOT_10c;
		     	else 
                    next = GOT_5c;
	        GOT_10c: 
                if (Q) 
                    begin
                      DC = 1; next = RETURN_5c;
                    end
                 else if (D) 
                     next = GOT_20c;
                 else if (N) 
                     next = GOT_15c;
                 else 
                     next = GOT_10c;
	         GOT_15c: 
                 if (Q) 
                     begin
		            	DC = 1; next = RETURN_10c;
		         	end
		      	else if (D) 
                    next = GOT_25c;
		      	else if (N) 
                    next = GOT_20c;
		      	else 
                    next = GOT_15c;
	         GOT_20c: 
                 if (Q) 
                     begin
		           		DC = 1; next = RETURN_15c;
		         	end
                  else if (D) 
                      begin
                         DC = 1; next = IDLE;
                      end
                  else if (N) 
                      next = GOT_25c;
                  else 
                      next = GOT_20c;
            GOT_25c: 
                if (Q) 
                    begin
                    	DC = 1; next = RETURN_20c;
                    end
            	else if (D) 
                    begin
                		DC = 1; next = RETURN_5c;
            	end
                else if (N) 
                    begin
                    	DC = 1; next = IDLE;
                	end
                else 
                    next = GOT_25c;
                    RETURN_20c: 
                        begin
                        	DD = 1; 
                            next = RETURN_10c;
                        end
                    RETURN_15c: 
                        begin
                            DD = 1; 
                            next = RETURN_5c;
                        end
                    RETURN_10c: 
                        begin
                        	DD = 1; 
                            next = IDLE;
                        end
                    RETURN_5c: 
                        begin
                        	DN = 1; 
                            next = IDLE;
                        end
                    default: 
                        next = IDLE;
            endcase
        end
endmodule

```



#### 3. 강의 7 Non blocking, Blocking [과제]

- ##### 과제 내용 숙지

- > Blocking : 해당 구문이 등장하는 시점에 할당이 이루어짐(=)
  >
  > Non Blocking : CLK 마지막 주기에 할당이 이루어짐 (<=)

``` verilog
module block_swap(x_out,y_out,clk,x,y);
  input clk,x,y;
  output x_out,y_out;
  reg x_val,y_val;
  
  always @(posedge clk) begin
     x_val = x;
     y_val = y;
	   x_val = y_val;
	   y_val = x_val;
  end
  
  assign x_out = x_val;
  assign y_out = y_val;
  
endmodule;
//Blocking떄는 순차적으로 바로 적용되어 교차가 이루어지지 않는다.
```

``` verilog
//Non Blocking떄는 정상적으로 교차가 이루어진다.
module nonblock_swap(x_out,y_out,clk,x,y);
  input clk,x,y;
  output x_out,y_out;
  reg x_val,y_val;
  
  always @(posedge clk) begin
     x_val = x;
     y_val = y;
	   x_val <= y_val;
	   y_val <= x_val;
  end
  
  assign x_out = x_val;
  assign y_out = y_val;
  
endmodule;
//Non Blocking떄는 일이 다 끝난후 할당되어 정상적으로 교차가 이루어진다.
```

``` verilog
module block_swap_tb;
  reg x,y,clk;
  wire x_out,y_out;
  
  
  block_swap bswap(x_out,y_out,clk,x,y);
  
  always #1 clk = !clk;
  
  initial begin
    x=0;y=0;clk=0;
    #4 x=0;y=1;
    #4 x=1;y=0;
    #4 x=1;y=1;
    #4 x=0;y=1;
  end

endmodule
```



#### 4. 강의 7 Delay-based timing [과제]



#### 5. 강의 7 Generate Blocks, Parallel block[과제]

- ##### Parallel block / fork , join



- ##### Sequential Block / begin, end



#### 6. 강의 8-9 Function Task [p10]

- ##### Example 8-7: Parity Calculation



#### 7. 강의 8-9 Automatic Function [p13]

- ##### 과제 내용 숙지



#### 8. 강의 8-9 assign구문 외우기 [p31 마지막줄]

- ##### 왜 저 구문이 필요할까?



#### 9. 강의 8-9 assign구문 외우기 [p23 밑에서 5번째줄]

- ##### 왜 저 구문이 필요할까?



#### 10. 강의 8-9 UART Transmitter [p23,25]

- ##### always구문 2개 숙지



#### 11. 강의 8-9 UART Receiver assign구문 외우기 [p?]

- ##### 왜 저 구문이 필요할까?



#### 10. 강의 8-9 UART Receiver [p32,35]

- ##### always구문 2개 숙지

