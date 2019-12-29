import math
chromatic = [440.0,466.16,493.88,523.25,554.37,587.33,622.25,659.26,698.46,739.99,783.99,830.61,880.0]

def quantlut():
    major = []
    quant_lut = []
    for i in [0,2,4,5,7,9,11,12,12]:
        major.append(chromatic[i])
    for i in range(440):
        quant_lut.append(major[round(i / 55.0)])
    l = 0
    line = ""
    for q in quant_lut:
        line+= "{},".format(q)
        l+= 1
        if l == 10:
            print(line)
            line = ""
            l = 0

def chordidxlut():
    line = ""
    l = 0
    for i in range(440):
        line+= "{},".format(round(i / 55.0))
        l+= 1
        if l == 40:
            print(line)
            line = ""
            l = 0

def chordlut():
    l = 0
    major = []
    for i in [0,2,4,5,7,9,11,12,12]:
        major.append(chromatic[i])
    deg = [0, 2, 4]
    for c in range(8):
        line = "{"
        for d in deg:
            idx = c + d
            if idx > 7:
                val =  (major[(idx - 7)] * 2) / major[0]
            else:
                val = major[idx] / major[0] 
            line+= "{},".format(val)
        print(line[:-1] + "},")


if __name__ == "__main__":
    chordidxlut()

