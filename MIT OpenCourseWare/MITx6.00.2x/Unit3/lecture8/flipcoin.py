import pylab, random
random.seed(0)

####################
## Helper functions#
####################
def flipCoin(numFlips):
    '''
    Returns the result of numFlips coin flips of a biased coin.

    numFlips (int): the number of times to flip the coin.

    returns: a list of length numFlips, where values are either 1 or 0,
    with 1 indicating Heads and 0 indicating Tails.
    '''
    with open('coin_flips.txt','r') as f:
        all_flips = f.read()
    flips = random.sample(all_flips, numFlips)
    return [int(flip == 'H') for flip in flips]


def getMeanAndStd(X):
    mean = sum(X)/float(len(X))
    tot = 0.0
    for x in X:
        tot += (x - mean)**2
    std = (tot/len(X))**0.5
    return mean, std

    
#############################
## CLT Hands-on		     #
##				     #
## Fill in the missing code #
## Do not use numpy/pylab   #
#############################
meanOfMeans, stdOfMeans = [], []
sampleSizes = range(10, 500, 50)

#中心极限定理 clt
#做三次关于中心极限定理的实验
#第一次的实验里，每个sample里都扔10次硬币 sampleSizes = 10
#第二次500个 sampleSizes = 500
#第三次50个 sampleSizes = 50
#每次实验都是取20个samples： for t in range(20):

#以第一次实验为例：
#我们取总共20个samples ： for t in range(20):
#每个sample扔10次硬币 ： sample = flipCoin(sampleSize)
#求出每个sample的平均值：
#sampleMeans.append(getMeanAndStd(sample)[0])
#sampleMeans里有20个数，每个数就是每次sample的平均值

#The Central Limit Theorem (CLT)
#这20个数的分布就是接近正态分布的
#这个分布的均值，就是掷硬币实验population的均值
#这个分布的方差，就是掷硬币实验population的（方差除以sample size）
#Given a sufficiently large sample:
#1) The means of the samples in a set of samples (the sample means) will be approximately normally distributed,
#2) This normal distribution will have a mean close to the mean of the population, and
#3) The variance of the sample means will be close to the variance of the population divided by the sample size.
#【clt】

#再求出20个sample的均值的（均值和标准差）
#也就是这个clt得到的正态分布的均值和标准差
#meanOfMeans.append(getMeanAndStd(sampleMeans)[0])
#stdOfMeans.append(getMeanAndStd(sampleMeans)[1])


def clt():
    for sampleSize in sampleSizes:
        sampleMeans = []
        for t in range(20):
            sample = flipCoin(sampleSize)## FILL THIS IN
            sampleMeans.append(getMeanAndStd(sample)[0])
        ## FILL IN TWO LINES
        ## WHAT TO DO WITH THE SAMPLE MEANS?
        #the sameple means is normally distributed
        #if we take the mean of the sample mean
        #it is the mean of the normal distribution
        meanOfMeans.append(getMeanAndStd(sampleMeans)[0])
        stdOfMeans.append(getMeanAndStd(sampleMeans)[1])
    

clt()
pylab.figure(1)
pylab.errorbar(sampleSizes, meanOfMeans,
               yerr = 1.96*pylab.array(stdOfMeans),
               label = 'Est. mean and 95% confidence interval')
pylab.xlim(0, max(sampleSizes) + 50)
pylab.axhline(0.65, linestyle = '--',
              label = 'True probability of Heads')
pylab.title('Estimates of Probability of Heads')
pylab.xlabel('Sample Size')
pylab.ylabel('Fraction of Heads (minutes)')
pylab.legend(loc = 'best')
pylab.show()


