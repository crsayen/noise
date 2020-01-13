import math
chromatic = [440.0,466.16,493.88,523.25,554.37,587.33,622.25,659.26,698.46,739.99,783.99,830.61,880.0]

C0	= 16.35
CS0 = 17.32
D0	= 18.35
DS0 = 19.45
E0	= 20.60
F0	= 21.83
FS0 = 23.12
G0	= 24.50
GS0 = 25.96
A0	= 27.50
AS0 = 29.14
B0	= 30.87
C1	= 32.70
CS1 = 34.65
D1	= 36.71
DS1 = 38.89
E1	= 41.20
F1	= 43.65
FS1 = 46.25
G1	= 49.00
GS1 = 51.91
A1	= 55.00
AS1 = 58.27
B1	= 61.74
C2	= 65.41
CS2 = 69.30
D2	= 73.42
DS2 = 77.78
E2	= 82.41
F2	= 87.31
FS2 = 92.50
G2	= 98.00
GS2 = 103.83
A2	= 110.00
AS2 = 116.54
B2	= 123.47
C3	= 130.81
CS3 = 138.59
D3	= 146.83
DS3 = 155.56
E3	= 164.81
F3	= 174.61
FS3 = 185.00
G3	= 196.00
GS3 = 207.65
A3	= 220.00
AS3 = 233.08
B3	= 246.94
C4	= 261.63
CS4 = 277.18
D4	= 293.66
DS4 = 311.13
E4	= 329.63
F4	= 349.23
FS4 = 369.99
G4	= 392.00
GS4 = 415.30
A4	= 440.00
AS4 = 466.16
B4	= 493.88
C5	= 523.25
CS5 = 554.37
D5	= 587.33
DS5 = 622.25
E5	= 659.25
F5	= 698.46
FS5 = 739.99
G5	= 783.99
GS5 = 830.61
A5	= 880.00
AS5	= 932.33
B5	= 987.77
C6	= 1046.50
CS6 = 1108.73
D6	= 1174.66
DS6 = 1244.51
E6	= 1318.51
F6	= 1396.91
FS6 = 1479.98
G6	= 1567.98
GS6 = 1661.22
A6	= 1760.00
AS6 = 1864.66
B6	= 1975.53
C7	= 2093.00
CS7 = 2217.46
D7	= 2349.32
DS7 = 2489.02
E7	= 2637.02
F7	= 2793.83
FS7 = 2959.96
G7	= 3135.96
GS7 = 3322.44
A7	= 3520.00
AS7 = 3729.31
B7	= 3951.07
C8	= 4186.01
CS8 = 4434.92
D8	= 4698.63
DS8 = 4978.03
E8	= 5274.04
F8	= 5587.65
FS8 = 5919.91
G8	= 6271.93
GS8 = 6644.88
A8	= 7040.00
AS8 = 7458.62
B8	= 7902.13

names = [
    "C0","CS0","D0","DS0","E0","F0","FS0","G0","GS0","A0","AS0","B0",
    "C1","CS1","D1","DS1","E1","F1","FS1","G1","GS1","A1","AS1","B1",
    "C2","CS2","D2","DS2","E2","F2","FS2","G2","GS2","A2","AS2","B2",
    "C3","CS3","D3","DS3","E3","F3","FS3","G3","GS3","A3","AS3","B3",
    "C4","CS4","D4","DS4","E4","F4","FS4","G4","GS4","A4","AS4","B4",
    "C5","CS5","D5","DS5","E5","F5","FS5","G5","GS5","A5","AS5","B5",
    "C6","CS6","D6","DS6","E6","F6","FS6","G6","GS6","A6","AS6","B6",
    "C7","CS7","D7","DS7","E7","F7","FS7","G7","GS7","A7","AS7","B7",
    "C8","CS8","D8","DS","E8","F8","FS8","G8","GS","A8","AS8","B8"
]

note_frequencies = [
    C0,CS0,D0,DS0,E0,F0,FS0,G0,GS0,A0,AS0,B0,
    C1,CS1,D1,DS1,E1,F1,FS1,G1,GS1,A1,AS1,B1,
    C2,CS2,D2,DS2,E2,F2,FS2,G2,GS2,A2,AS2,B2,
    C3,CS3,D3,DS3,E3,F3,FS3,G3,GS3,A3,AS3,B3,
    C4,CS4,D4,DS4,E4,F4,FS4,G4,GS4,A4,AS4,B4,
    C5,CS5,D5,DS5,E5,F5,FS5,G5,GS5,A5,AS5,B5,
    C6,CS6,D6,DS6,E6,F6,FS6,G6,GS6,A6,AS6,B6,
    C7,CS7,D7,DS7,E7,F7,FS7,G7,GS7,A7,AS7,B7,
    C8,CS8,D8,DS8,E8,F8,FS8,G8,GS8,A8,AS8,B8
]

def generate_note_ranges():
    floor = 0
    ciel = 0
    for i, f in enumerate(note_frequencies):
        if i == len(note_frequencies) - 1:
            break
        diff = note_frequencies[i + 1] - f
        ciel = f + diff / 2
        print(f"{floor}, {i + 1}")
        floor = ciel
    print(floor)
    print(10000.0)

def generate_frequency_lut():
    for i, note in enumerate(note_frequencies):
        print(f"{note},{i + 1}")

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

"""

major:  4:5:6
minor:  10:12:15
7:      20:25:30:36
min7:   10:12:15:18
maj7:   8:10:12:15

"""


if __name__ == "__main__":
    generate_frequency_lut()

