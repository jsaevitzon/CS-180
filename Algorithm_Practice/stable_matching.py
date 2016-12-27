
def stable(mp, fp, n):
    #mp, fp take form [[0, []]]
    #if mp[n][0] = 0, not married, else married
    
    count = 0
    #choose a man that is not married


    i = 0
    while i < n:
        if mp[i][0]==0:
            numF = mp[i][1][0]
            #if fp is not engaged
            if fp[numF-1][0]==0:
                mp[i][0] = numF #mp[i][0] set to female index
                fp[numF-1][0] = i+1 #fp[j][0] set to male index
            
            #else female is engaged to mprime
            else:
                mPrime = fp[numF-1][0] 

            #if female prefers m[i] to mPrime
                if fp[numF-1][1].index(i+1) < fp[numF-1][1].index(mPrime):
               #set mp[mprime-1][0] to 0
                    mp[mPrime-1][0] = 0 #no longer engaged
                    
                #engage the two partners
                    fp[numF-1][0] = i+1
                    mp[i][0] = numF
            
            mp[i][1].remove(mp[i][1][0])
            i = 0
            count = count + 1
        else:
            i = i + 1
        #remove the top partner from male list
                           
    #very specific case...
    return mp[0][0], mp[1][0], mp[2][0], mp[3][0], mp[4][0], count







#mp[0] or fp[0] == 1(taken) or 0 (not)




# list of males
mone =   [0, [1, 3, 2, 4, 5]]
mtwo =   [0, [2, 5, 3, 4, 1]]
mthree = [0, [1, 3, 2, 4, 5]]
mfour =  [0, [5, 3, 1, 2, 4]]
mfive =  [0, [2, 3, 4, 5, 1]]

# list of females
fone =   [0, [1, 4, 3, 2, 5]]
ftwo =   [0, [2, 1, 4, 5, 3]]
fthree = [0, [5, 2, 3, 1, 4]]
ffour =  [0, [5, 3, 2, 1, 4]]
ffive =  [0, [1, 5, 2, 3, 4]]

print stable( [mone, mtwo, mthree, mfour, mfive],
        [fone, ftwo, fthree, ffour, ffive], 5)
