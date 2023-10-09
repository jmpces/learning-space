import math

def cba(DevCost,BenefitCost,OperatingCost,YearlyDiscountFactors, BenefitIncrease):

    # year 0
    CumulativeNetPresetVal = DevCost

    YearsTable = [
        [0, YearlyDiscountFactors[0], 0, DevCost, 0,
        YearlyDiscountFactors[0], 0,
        DevCost,
        CumulativeNetPresetVal]
    ]

    YearlyDiscountFactors = YearlyDiscountFactors[1:]

    # Pre-Computations
    ValOfBenefits = BenefitCost
    initial = True
    NotPayed = True

    TotalPresentValueOfBenefits = 0
    TotalPresentValueOfCost = 0
    TotalPresentValOfNetBenefitAndCost = 0

    YearCnt = 0

    # remaining years
    for cf in YearlyDiscountFactors:
        YearCnt += 1
        if initial:
            initial = False
        else:
            ValOfBenefits = ValOfBenefits + ValOfBenefits * BenefitIncrease
        PresentValueOfBenefits = round(ValOfBenefits*cf)
        PresentValueOfCost = round(OperatingCost*cf)
        PresentValOfNetBenefitAndCost = PresentValueOfBenefits - PresentValueOfCost
        
        TotalPresentValueOfBenefits += PresentValueOfBenefits
        TotalPresentValueOfCost += PresentValueOfCost
        TotalPresentValOfNetBenefitAndCost += PresentValOfNetBenefitAndCost

        CurrYear = [
            ValOfBenefits,cf,
            PresentValueOfBenefits,0,
            OperatingCost, cf, PresentValueOfCost,
            PresentValOfNetBenefitAndCost,
            CumulativeNetPresetVal-PresentValOfNetBenefitAndCost
        ]
        
        YearsTable.append(CurrYear)
        
        Previous = CumulativeNetPresetVal
        CumulativeNetPresetVal-=PresentValOfNetBenefitAndCost

        if CumulativeNetPresetVal < 0 and NotPayed:
            NotPayed = False
            PayedYear = YearCnt
            Months = Previous/(abs(CumulativeNetPresetVal)+Previous) * 12
            Days = round((Months - int(Months))*30)

    ROI = (TotalPresentValueOfBenefits-(DevelopmentCost+TotalPresentValueOfCost))/(DevelopmentCost+TotalPresentValueOfCost)*100
    
    Totals = {
        'Total Present Value Of Benefits' : TotalPresentValueOfBenefits,
        'Total Present Value Of Cost' : TotalPresentValueOfCost,
        'Total Present Value Of NetBenefitAndCost' : TotalPresentValOfNetBenefitAndCost,
        'ROI' : ROI,
    }

    PaybackPeriod = {
        'Year' : PayedYear,
        'Month' : round(Months),
        'Days' : round(Days)
    }
    return YearsTable, Totals, PaybackPeriod

factors = [1,0.9091,0.8264,0.7513,0.6830,0.6209]

DevelopmentCost = round(22887.73)
BenefitCost = round(24000)
OperationCost = round(2387.73)
BenefitIncrease = 0.05

YearTables, Totals, PaybackYearPeriod = cba(
    DevelopmentCost,
    BenefitCost,
    OperationCost,
    factors,
    BenefitIncrease
)

for rows in YearTables:
    print(rows)

print()
for e in Totals:
    print(f"{e} = {Totals[e]}")

print(f"\nPayback Period : {PaybackYearPeriod}")
