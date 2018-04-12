# 3 Jednosměrný seznam

Máte k dispozici obousměrný seznam implementovaný pomocí spojových struktur, zdrojový kód je uveden v přílohách A a B. Implementace je dále dostupná na:

  [LINK](http://www.cs.vsb.cz/dvorsky/Download/ALGII/ProjectI/List.zip)

Vaším úkolem je upravit daný zdrojový kód tak, aby implementoval jednosměrný seznam. To znamená, že položky seznamu **`ListItem`** budou obsahovat kromě hodnoty **`Value`** již jen pointer **`Next`**. Je jasné, že některých funkcí se úprava nedotkne, jiných jen minimálně, ale ně které budepotřeba  implementovat  prakticky  znovu,  přičemž  jejich  efektivita^1  se  může  zároveň výrazně zhoršit ve srovnání s obousměrným seznamem. V tomto zadání se nehraje na efektivitu manipulací se seznamem, ale důraz je kladen na zvládnutí komplikovanějších manipulací s pointery a seznamem obecně. Samozřejměsi můžete implementovat další pomocné funkce.

---
>^1Což ovšem neznamená, že je dovoleno psát zcela šílené kódy s poznámkou, že „jsou funkční“. I v tomto případě je nutné si zachovat zdravý rozum.
