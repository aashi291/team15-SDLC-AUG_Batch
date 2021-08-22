# Introduction
1. There will always be differing opinions on how frequently to trade, how long to hold a position, and when to enter or exit the market. Our emotions influence our trading decisions as humans. <br />
2. Rule Based Trading is the solution to this problem. Using a Rule Based Trading Style, one can back test the strategy and use it to make trade calls.<br />
3. This Trading Strategy Tester will back test the strategy and make trading recommendations.


# Features

This Trading Strategy Tester's various festivities include:

1. Can make buy and sell recommendations based on stock prices.csv document
2. Back testing the strategy on stocks is simple by downloading the.csv file from nseindia.com.
3. Provides the date and price at which the stock can be purchased and sold.


# Defining the System


## SWOT Analysis
![SWOT](https://user-images.githubusercontent.com/86605697/130112556-7f1c0310-7635-4fd4-ac64-84ac16d0e38f.png)



# 4W's and 1'H

### Who
This module targets the Retail Traders.
### What
This utility is used to back test the rule based trading strategy.
### When
This can be used to the retail trader want to test new trading strategy or check it the strategy works on a particular stock.
### Where
This can be used in stock market.
### How
The utility can be used by giving .csv file of any stock which can be easily downloaded from nseindia.com.

# Detail Requirements
## High Level Requirements:

| ID     |                    Description                                     |     Status   |
|:------:|:------------------------------------------------------------------:|:------------:|
| HR_01  | Read .csv File                                                     | Implemented  |
| HR_02  | User should be able to choose a strategy for Backtesting           | Implemented  |
| HR_03  | Trade calls                                                        | Implemented  |
| HR_04  | Backtest Performance parameters                                    | Implemented  |
| HR_05  | Display Results                                                    | Implemented  |


## Low Level Requirements:

|    ID  |                     Description                          | HR_ID   |    Status    |
|:------:|:--------------------------------------------------------:|:-------:|:------------:|
| LR_01  | To read Individual columns of .csv files                 |  HR_01  | Implemented  |
| LR_02  | Implement Moving Average Convergence Divergence strategy |  HR_02  | Implemented  |
| LR_03  | Implement Rate of Change strategy                        |  HR_02  | Implemented  |
| LR_04  | Implement Williams %R strategy                           |  HR_02  | Implemented  |
| LR_05  | Implement Weighted Moving Average strategy               |  HR_02  | Implemented  |
| LR_06  | Implement Hull Moving Average strategy                   |  HR_02  | Implemented  |
| LR_07  | Implement Relative Strength Index strategy               |  HR_02  | Implemented  |
| LR_08  | Implement Money Flow Index strategy                      |  HR_02  | Implemented  |
| LR_09  | Implement Exponential Moving Average strategy            |  HR_02  | Implemented  |
| LR_10  | Implement Bollinger Bands strategy                       |  HR_02  | Implemented  |
| LR_11  | Implement Stochastic Indicator                           |  HR_02  | Implemented  |
| LR_12  | Buy/Sell	                                                |  HR_03  |	Implemented  |
| LR_13  | Price                                                   	|  HR_03  | Implemented  |
| LR_14  | Date                                                     |	 HR_03  |	Implemented  |
| LR_15  | Total Profit/Loss %                                      |	 HR_04  |	Implemented  |
| LR_16  | Total Trades Closed                                     	|  HR_04  |	Implemented  |
| LR_17  | Profit Factor	                                          |  HR_04  | Implemented  |
