import json
import math
import numpy as np

from IPython.display import display
from pandas.tseries import frequencies
from tabulate import tabulate
import pandas as pd

if __name__ == "__main__":
    with open('patient_age.json') as f:
        json_data = json.load(f)
    
    data = json_data['patient_age']
    N = len(data)

    # ===================== find the range (R), number of classes (K) and class interval (C) ===================== 
    LV = data[0]
    HV = data[0]

    for f in data:
        if f < LV:
            LV = f
        if f > HV:
            HV = f

    R = HV - LV
    K = round(math.sqrt(N))
    C = round(R / K) # can can be overwritten

    print("N =", N)
    print("R =", R)
    print("K =", K)
    print("C =", C)

    # ===================== construct the fdt table columns ===================== 

    Limits = []
    Limits_String = []
    Frequency = []
    LTCB = []
    UTCB = []
    CM = []

    current_lv = LV

    for i in range(K):
        # ------------------- limits ------------------- 
        limit = {
            "lower": current_lv,
            "upper": current_lv + C - 1
        }

        Limits.append(limit)
        Limits_String.append("{}-{}".format(limit['lower'], limit['upper']))

        current_lv += C

        Frequency.append(0)

        # ------------------- LTCB -------------------
        LTCB.append(limit['lower'] - 0.5)
        # ------------------- UTCB -------------------
        UTCB.append(limit['upper'] + 0.5)
        # ------------------- CM -------------------
        CM.append((limit['lower'] + limit['upper']) / 2)


    for f in data:
        # ------------------- count frequency -------------------
        # range-key map
        Frequency[(f - LV) // C] += 1

    RF = []
    RF_Percentage = []

    Less_CF = []
    less_cf_accumulate = 0

    Great_CF = []
    great_cf_dissipate = np.sum(np.array(Frequency))

    for f in Frequency:
        # ------------------- RFs -------------------
        rf = f / N
        RF.append(rf)
        RF_Percentage.append(rf * 100)
        # ------------------- <>CFs -------------------
        less_cf_accumulate += f
        Less_CF.append(less_cf_accumulate)
        Great_CF.append(great_cf_dissipate)
        great_cf_dissipate -= f

    Less_RCF = []
    less_rcf_accumulate = 0

    Great_RCF = []
    great_rcf_dissipate = 100.0

    for rf in RF_Percentage:
        # ------------------- <>RCFs -------------------
        less_rcf_accumulate += rf
        Less_RCF.append(less_rcf_accumulate)
        Great_RCF.append(great_rcf_dissipate)
        great_rcf_dissipate -= rf

    # ===================== Check column lengths =====================
    print("Limits len    =", len(Limits))
    print("Frequency len =", len(Frequency))
    print("LTCB len      =", len(LTCB))
    print("UTCB len      =", len(UTCB))
    print("CM len        =", len(CM))
    print("RF len        =", len(RF))
    print("RF_Percentage =", len(RF_Percentage))
    print("Less_CF len   =", len(Less_CF))
    print("Great_CF len  =", len(Great_CF))
    print("Less_RCF len  =", len(Less_RCF))
    print("Great_RCF len =", len(Great_RCF))

    # ===================== print the FDT ===================== 
    fdt_table = {
        'Class': Limits_String,
        'f': Frequency,
        'UTCB': UTCB,
        'LTCB': LTCB,
        'CM': CM,
        'RF': RF,
        '(%)RF': RF_Percentage,
        '<CF': Less_CF,
        '>CF': Great_CF,
        '<RCF': Less_RCF,
        '>RCF': Great_RCF
    }

    data_frame = pd.DataFrame(fdt_table)
    # display(data_frame)
    print(tabulate(data_frame, headers = 'keys', tablefmt = 'psql'))
