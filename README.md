# Whack-A-Mole

Dieses Repository enthält eine C‑Implementierung des Spiels „Hau den Maulwurf“, entwickelt unter Beachtung von einigen MISRA‑C‑Standards.

## Anforderungen

| Anforderung        | Beschreibung |
|--------------------|--------------|
| REQ-IDLE           | Idle-Zustand. Das Spiel wird bei Knopfdruck initialisiert. |
| REQ-INIT           | (Low Priority) Sequenz, in der die Lampen blinken. |
| REQ-GAME-TIME      | Das Spiel läuft exakt 30 Sekunden. |
| REQ-GAME-HIT       | Wird ein leuchtender Knopf gedrückt, erhöht sich der Score um +1 und die Lampe geht aus. |
| REQ-GAME-MISS      | Wird ein nicht leuchtender Knopf gedrückt, verringert sich der Score um -1. Der minimale Punktestand ist 0. |
| REQ-PHASE          | Eine oder mehrere Lampen leuchten auf. Knöpfe bleiben aktiv, bis sie gedrückt wurden. Eine Phase endet, wenn alle leuchtenden Knöpfe gedrückt wurden. |
| REQ-PHASE-PROB     | Wahrscheinlichkeit der Anzahl leuchtender Lampen pro Phase:<br>1 Lampe: 70 %<br>2 Lampen: 20 %<br>3 Lampen: 7 %<br>4 Lampen: 3 % |
