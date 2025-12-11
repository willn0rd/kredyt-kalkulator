const API_URL = 'https://kredyt-kalkulator-willn0rd.azurewebsites.net/docs'; // Zmień na Azure URL po wdrożeniu

async function oblicz() {
    const bank = document.getElementById('bank').value;
    const kwota = parseFloat(document.getElementById('kwota').value);
    const lata = parseInt(document.getElementById('lata').value);

    if (!kwota || !lata) {
        alert('Wypełnij wszystkie pola!');
        return;
    }

    try {
        const response = await fetch(`${API_URL}/kalkulacja`, {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ bank, kwota, lata })
        });

        const data = await response.json();

        // Wyświetl wyniki
        document.getElementById('wyniki').style.display = 'block';
        document.getElementById('wynik-bank').textContent = data.bank;
        document.getElementById('rata').textContent = data.rata_miesieczna.toLocaleString('pl-PL');
        document.getElementById('koszt').textContent = data.calkowity_koszt.toLocaleString('pl-PL');

        // Tabela symulacji (pierwsze 12 miesięcy)
        const tabela = document.getElementById('tabela-symulacji');
        tabela.innerHTML = `
            
                Miesiąc
                Rata (zł)
                Pozostało (zł)
            
        `;

        data.symulacja.slice(0, 12).forEach(m => {
            tabela.innerHTML += `
                
                    ${m.miesiac}
                    ${m.rata.toLocaleString('pl-PL')}
                    ${m.pozostalo.toLocaleString('pl-PL')}
                
            `;
        });

    } catch (error) {
        alert('Błąd połączenia z API: ' + error.message);
    }
}