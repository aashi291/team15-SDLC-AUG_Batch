# Test plan and Test Output

## Low level

### Indicators:

|    ID  |                     Description                          | Expected input | Expected output | Actual output | Type of test |
|:------:|:--------------------------------------------------------:|:--------------:|:---------------:|:-------------:|:------------:|
|   `ID1`   |   Indicator used in Exponential moving average            | ema(26,10,close)                                                      | 2776.48    |   | Scenario based |
|   `ID2`   |   Indicator used in William%R strategy                    | William%R(100,14,close{previous day,highOfLast14days,lowOfLast14days) | 48.618     |   | Scenario based |
|   `ID3`   |   Indicator used in William%R strategy                    | DMA(100,close)                                                        | 2718.1775  |   | Scenario based |
|   `ID4`   |   Indicator used in macd Strategy                         | macd(12,26,10,close)                                                  | 70.93      |   | Scenario based |
|   `ID5`   |   Indicator used in rsi Strategy                          | rsi(14,10,high,low)                                                   | 50.7496    |   | Scenario based |
|   `ID6`   |   Indicator used for Bollinger Bands Strategy             | upperBand(2,20,362,close)                                             | 1773.41702 |   | Scenario based |
|   `ID7`   |   Indicator used for Bollinger Bands Strategy             | lowerBand(2,20,362,close)                                             | 1452.46298 |   | Scenario based |
|   `ID8`   |   Indicator used for Triangular Moving Average Strategy   | TMA-Triangular Moving Average(26,10,close)                            | 2798       |   | Scenario based |
|   `ID9`   |   Indicator used in ROC strategy                          | roc(20,10,close)                                                      | 6.4407     |   | Scenario based |
|   `ID10`  |   MFI Indicator                                           | mfi(ArrayName)                                                        | 78.1977    |   | Scenario based |
|   `ID11`  |   Indicator used in Weighted moving average Strategy      | WMA(10,20,close)                                                      | 2096.5     |   | Scenario based |
|   `ID12`  |   Stochastic Oscillator                                   | funforK(14,369,close,HIGH,LOW)                                        | 64.3270    |   | Scenario based |


### Strategies:

|    ID  |                     Description                          | Expected input | Expected output | Actual output | Type of test |
|:------:|:--------------------------------------------------------:|:--------------:|:---------------:|:-------------:|:------------:|
|   `ID1`   |   WillR strategy                  | Data from .csv file           | Buy and sell to make maximum profits    | Buy when willR >50 and closing>100 DMA and inTrade status is close. Sell when WillR<50 or closing <100 DMA and inTrade status is open | Scenario based |
|   `ID2`   |   macdStrategy                    | Data from .csv file           | Buy when macd>0  Sell when macd<0    |   |  |
|   `ID3`   |   bollingerStrategy               | Data from .csv file           | Buy when lowerBand >closePrice and inTrade status is close Sell when upperBand<closePrice and inTrade status is open    |   |  |
|   `ID4`   |   TMA-Triangular Moving Average   | Data from .csv file           | Buy at crossover, when TMA of previous day < price of previous day Sell at crossover, when TMA of previous day > price of previous day    |   |  |
|   `ID5`   |   ROC-Rate Of Change            | Data from .csv file         | Sell at ROC>0 Buy at ROC<0    |   |  |
|   `ID6`   |   emaStrategy                   | Data from .csv file         | Buy when EMA(14)>EMA(28) Sell when EMA(14)<EMA(28)    |   |  |
|   `ID7`   |   MFI Indicator                 | Data from .csv file         | Buy When MFI<20 Sell When MFI>80    | Buy When MFI<20Sell When MFI>80  | Scenario based |
|   `ID8`   |   wmaStrategy                   | Data from .csv file         | Buy when WMA(14)>WMA(28) Sell when WMA(14)<WMA(28)    |   |  |
|   `ID9`   |   Stochastic                    | Data from .csv file         | If K<20 && D<20 && K<D --> BUY ; IF K>80 && D>80 &&K>D --> SELL    |   | Scenario based |
  
  
  
  
  
## High level
  
|                     Description                          | Expected input | Expected output | Actual output | Type of test |
|:--------------------------------------------------------:|:--------------:|:---------------:|:-------------:|:------------:|
|   Input data            | .csv file from NSE      | Read and identify values for close,high low etc.   | Read and identify data from .csv file  | technical|
|   Select strategy       | User select options only from the displayed options          | Performance parameters of selected strategy    | Performance is calculated and displayed | technical |
  
 









