# GPIO
Obsługa wejść i wyjść

## UWAGI:
* w funkcjach: <b>void GPIO_set_pin_as_input(LINE_t *pLine)</b>, <b>void GPIO_set_pin_as_output(LINE_t *pLine),</b> zamiast linii <b>LL_AHB2_GRP1_EnableClock(pLine->enable_periph);</b> można użyć

<b>if(line->port == GPIOA)	LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);

if(line->port == GPIOB)	LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB);

if(line->port == GPIOC)	LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOC);
</b>
