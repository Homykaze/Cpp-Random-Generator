# Pseudo-random number generator
This is a pseudo-random number generator, which is based on the results of its previously generated values and a prime number of any choice. The algorithm formula is as follows:<br>

### *R = (prev1 + prev2 + prev3 + prev4) % 211*.<br>

Prime 211 was selected to see statistics in the range [0, 210] (prime numbers greater than 211 will do the same job just fine) inclusively for 100 000 cases, which seem to be distributed quite evenly. And each generated number actually feels random.<br>

In order to increase the range of possible values, the smallest greater than the upper limit value prime number needs to be used in the formula instead of 211. To specify the range to be precise the formula may be adjusted to the following one:<br>

### *R = min + ((prev1 + prev2 + prev3 + prev4) % PRIME_NUMBER) % (max - min + 1)*,<br> 

the base case should be changed to return *min*, for example. This formula will generate numbers in the exactly provided range [min, max] inclusively, but keep in mind that *PRIME_NUMBER* needs to be greater or equal to *max*. The distribution of values doesn't vary too much and seems quite even.<br>

The reason for prime numbers to be used in this project is to achieve the most even distribution amongst possible values. Of course, it will never be perfectly even, but it will be very close to being even, which is what we usually want from random-number generators. If we selected 210, for instance, every value divisible by factors 2, 3, 5, 7 (prime factors of 210) would eliminate sums purely consisting of numbers 2, 3, 5, 7 and the ones consisting their products, which will result in some numbers not being generated at all, such as: 2, 4, 8, 16, 32..., or 3, 9, 27, 81..., or 5, 25, 125.., or 7, 49..., whereas division by prime numbers always results with remainders, which will always (let alone consistency) result in at least some cases of pseudo-random number generation.<br>

The program also lets user input their own values to see the outputs based on their input. The way random numbers are usually generated is by using current time in seconds as input, which is always unique, though predictable, however, not knowing the math formula for number generation will simulate the unpredictable behaviour, which is what we want from generating random numbers.
