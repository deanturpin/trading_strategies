[![Build Status](https://travis-ci.org/deanturpin/handt.svg?branch=master)](https://travis-ci.org/deanturpin/handt)

**History is no indicator of future performance. Don't invest what you can't
afford to lose.**

Having said that... *Have A Nice Day Trader* is an algorithmic trading platform
that uses patterns in historic prices to forecast prospective trades. Prices
are requested for all currency pairs traded by Binance and Coinbase over the
last 80 days. A library of strategies is backtested over all pairs and the
summary below is generated.

Prices are fetched using the [CryptoCompare
API](https://min-api.cryptocompare.com/).

---

Generated Mon 1 Oct 08:39:18 GMT 2018
* 2 currency pairs
* 6,600 strategy/pair combinations
* 11,792,094 backtests

# Current prospects
Prospects based on prices from the last 24 hours.

Strategy|Pair|Good/Bad|Spot|Last (days)
---|---|---|---|---
Leaping-Lundehund-2|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|14/59|7.41e-05|
Leaping-Lundehund-3|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|14/59|7.41e-05|
Leaping-Lundehund-4|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|14/59|7.41e-05|
Leaping-Lundehund-5|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|14/59|7.41e-05|
Leaping-Lundehund-6|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|14/59|7.41e-05|
Leaping-Lundehund-7|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|14/59|7.41e-05|
Leaping-Lundehund-8|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|14/59|7.41e-05|
Leaping-Lundehund-9|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|14/59|7.41e-05|
Leaping-Lundehund-10|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|14/59|7.41e-05|
Leaping-Lundehund-11|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|14/59|7.41e-05|
Leaping-Lundehund-12|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|14/59|7.41e-05|

# 80-day backtest
The results are ordered by success which is measured using the proportion of
good to bad trades.

Strategy|Pair|Good/Bad|Spot
---|---|---|---
Crouching-Munchkin-7|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|5/1|7.41e-05
Darting-Munchkin-7|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|5/1|7.41e-05
Crouching-Munchkin-7|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|4/1|0.002132
Leaping-Bandicoot-3|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|4/1|0.002132
Darting-Munchkin-7|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|4/1|0.002132
Crouching-Jagdterrier-9|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|7/2|7.41e-05
Darting-Jagdterrier-9|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|7/2|7.41e-05
Crouching-Jagdterrier-19|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Crouching-Jagdterrier-20|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Crouching-Affenpinscher-15|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Crouching-Affenpinscher-16|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Crouching-Munchkin-8|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Crouching-Cricket-19|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Crouching-Cricket-20|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Crouching-Axolotl-19|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Crouching-Axolotl-20|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Crouching-Pomeranian-15|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Crouching-Pomeranian-16|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Leaping-Munchkin-7|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Leaping-Munchkin-8|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Darting-Jagdterrier-19|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Darting-Jagdterrier-20|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Darting-Affenpinscher-15|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Darting-Affenpinscher-16|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Darting-Munchkin-8|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Darting-Cricket-19|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Darting-Cricket-20|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Darting-Axolotl-19|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Darting-Axolotl-20|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Darting-Havanese-19|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Darting-Havanese-20|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Darting-Pomeranian-15|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Darting-Pomeranian-16|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/0|0.002132
Crouching-Jagdterrier-18|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/0|7.41e-05
Crouching-Jagdterrier-19|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/0|7.41e-05
Crouching-Affenpinscher-15|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/0|7.41e-05
Crouching-Munchkin-8|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/0|7.41e-05
Crouching-Bandicoot-4|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/0|7.41e-05
Darting-Jagdterrier-18|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/0|7.41e-05
Darting-Jagdterrier-19|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/0|7.41e-05
Darting-Affenpinscher-15|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/0|7.41e-05
Darting-Munchkin-8|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/0|7.41e-05
Darting-Bandicoot-4|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/0|7.41e-05
Darting-Pomeranian-15|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/0|7.41e-05
Crouching-Jagdterrier-16|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/1|0.002132
Crouching-Jagdterrier-17|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/1|0.002132
Crouching-Jagdterrier-18|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/1|0.002132
Crouching-Affenpinscher-13|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/1|0.002132
Crouching-Affenpinscher-14|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/1|0.002132
Crouching-Axolotl-18|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/1|0.002132
Leaping-Griffon-7|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/1|0.002132
Leaping-Pomeranian-6|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|6/2|0.002132
Darting-Jagdterrier-16|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/1|0.002132
Darting-Jagdterrier-17|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/1|0.002132
Darting-Jagdterrier-18|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/1|0.002132
Darting-Affenpinscher-13|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/1|0.002132
Darting-Affenpinscher-14|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/1|0.002132
Darting-Axolotl-18|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/1|0.002132
Darting-Pomeranian-13|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/1|0.002132
Darting-Pomeranian-14|[SALT-ETH](https://binance.com/en/trade/SALT_ETH)|3/1|0.002132
Crouching-Jagdterrier-17|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/1|7.41e-05
Crouching-Affenpinscher-13|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/1|7.41e-05
Crouching-Affenpinscher-14|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/1|7.41e-05
Crouching-Munchkin-9|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/1|7.41e-05
Crouching-Cricket-18|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/1|7.41e-05
Crouching-Cricket-19|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/1|7.41e-05
Crouching-Axolotl-18|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/1|7.41e-05
Crouching-Axolotl-19|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/1|7.41e-05
Darting-Jagdterrier-17|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/1|7.41e-05
Darting-Affenpinscher-13|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/1|7.41e-05
Darting-Affenpinscher-14|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/1|7.41e-05
Darting-Munchkin-9|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/1|7.41e-05
Darting-Cricket-18|[SALT-BTC](https://binance.com/en/trade/SALT_BTC)|3/1|7.41e-05
