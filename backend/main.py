from fastapi import FastAPI #Glowna klasa w moim API
from fastapi.middleware.cors import CORSMiddleware #Cross Origin Resource Sharing, frontend na git, backend na localhost i wszystko sie laczy
from pydantic import BaseModel #Klasa walidacji danych, automatycznie sprawdza czy dane w JSON sa poprawne
from typing import List #typ danych lista

app = FastAPI(title="Kalkulator Kredytu Hipotecznego")

#Polaczenie z frontendem
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

#RRSO bankow - poprawic na dynamiczne pobierające ze stron www
BANKI = {
    "mBank": 6.83,
    "Millennium": 8.88,
    "Santander": 7.57,
    "Alior Bank": 7.22,
    "ING": 7.74
}

class KredytRequest(BaseModel):
    bank: str
    kwota: float
    lata: int

class RataResposne(BaseModel):
    rrso: float
    miesiac: int
    pozostalo: float

class KredytResponse(BaseModel):
    bank: str
    rrso: float
    kwota_kredytu: float
    lata: int
    calkowity_koszt: float
    rata_miesieczna: float
    symulacja: List[RataResponse]

@app.get("/")
def root():
    return {"message": "Kalkulator Kredytów Hipotecznych", "status": "online"}

@app.get("/banki")
def get_banki():
    return [{"nazwa": k, "rrso": v} for k, v in BANKI.items()]

@app.post("/kalkulacja", response_model=KredytResponse)
def kalkulacja_kredytu(req: KredytRequest):
    # Walidacja
    if req.bank not in BANKI:
        return {"error": "Nieznany bank"}
    if req.lata < 1 or req.lata > 35:
        return {"error": "Lata muszą być między 1-35"}
    
    rrso = BANKI[req.bank]
    dni = req.lata * 365
    miesiac = req.lata * 12
    
    # Wzór z C++
    koszt = (rrso / 100.0) * req.kwota * (dni / 365.0)
    calosc = koszt + req.kwota
    rata = calosc / miesiac
    
    # Symulacja spłat
    symulacja = []
    pozostalo = calosc
    
    for i in range(1, miesiac + 1):
        pozostalo -= rata
        symulacja.append(RataResponse(
            miesiac=i,
            rata=round(rata, 2),
            pozostalo=round(max(0, pozostalo), 2)
        ))
    
    return KredytResponse(
        bank=req.bank,
        rrso=rrso,
        kwota_kredytu=req.kwota,
        lata=req.lata,
        calkowity_koszt=round(calosc, 2),
        rata_miesieczna=round(rata, 2),
        symulacja=symulacja
    )

# Health check dla Azure
@app.get("/health")
def health():
    return {"status": "healthy"}