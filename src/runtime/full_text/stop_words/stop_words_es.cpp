/*
 * Copyright 2006-2016 zorba.io
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "stdafx.h"

#include "utf8_chars.h"

namespace zorba {

//
// These words come from http://snowball.tartarus.org/.
//
extern char const *const stop_words_es[] = {
  "a",
  "al",
  "algo",
  "algunas",
  "algunos",
  "ante",
  "antes",
  "como",
  "con",
  "contra",
  "cual",
  "cuando",
  "de",
  "del",
  "desde",
  "donde",
  "durante",
  "e",
  "el",
  eacute "l",
  "ella",
  "ellas",
  "ellos",
  "en",
  "entre",
  "era",
  "erais",
  eacute "ramos",
  "eran",
  "eras",
  "eres",
  "es",
  "esa",
  "esas",
  "ese",
  "eso",
  "esos",
  "esta",
  "est" aacute,
  "estaba",
  "estabais",
  "est" aacute "bamos",
  "estaban",
  "estabas",
  "estad",
  "estada",
  "estadas",
  "estado",
  "estados",
  "est" aacute "is",
  "estamos",
  "est" aacute "n",
  "estando",
  "estar",
  "estar" aacute,
  "estar" aacute "n",
  "estar" aacute "s",
  "estar" eacute,
  "estar" eacute "is",
  "estaremos",
  "estar" iacute "a",
  "estar" iacute "ais",
  "estar" iacute "amos",
  "estar" iacute "an",
  "estar" iacute "as",
  "estas",
  "est" aacute "s",
  "este",
  "est" eacute,
  "est" eacute "is",
  "estemos",
  "est" eacute "n",
  "est" eacute "s",
  "esto",
  "estos",
  "estoy",
  "estuve",
  "estuviera",
  "estuvierais",
  "estuvi" eacute "ramos",
  "estuvieran",
  "estuvieras",
  "estuvieron",
  "estuviese",
  "estuvieseis",
  "estuvi" eacute "semos",
  "estuviesen",
  "estuvieses",
  "estuvimos",
  "estuviste",
  "estuvisteis",
  "estuvo",
  "fue",
  "fuera",
  "fuerais",
  "fu" eacute "ramos",
  "fueran",
  "fueras",
  "fueron",
  "fuese",
  "fueseis",
  "fu" eacute "semos",
  "fuesen",
  "fueses",
  "fui",
  "fuimos",
  "fuiste",
  "fuisteis",
  "ha",
  "hab" eacute "is",
  "haber",
  "hab" iacute "a",
  "hab" iacute "ais",
  "hab" iacute "amos",
  "hab" iacute "an",
  "hab" iacute "as",
  "habida",
  "habidas",
  "habido",
  "habidos",
  "habiendo",
  "habr" aacute,
  "habr" aacute "n",
  "habr" aacute "s",
  "habr" eacute,
  "habr" eacute "is",
  "habremos",
  "habr" iacute "a",
  "habr" iacute "ais",
  "habr" iacute "amos",
  "habr" iacute "an",
  "habr" iacute "as",
  "han",
  "has",
  "hasta",
  "hay",
  "haya",
  "hay" aacute "is",
  "hayamos",
  "hayan",
  "hayas",
  "he",
  "hemos",
  "hube",
  "hubiera",
  "hubierais",
  "hubi" eacute "ramos",
  "hubieran",
  "hubieras",
  "hubieron",
  "hubiese",
  "hubieseis",
  "hubi" eacute "semos",
  "hubiesen",
  "hubieses",
  "hubimos",
  "hubiste",
  "hubisteis",
  "hubo",
  "la",
  "las",
  "le",
  "les",
  "lo",
  "los",
  "m" aacute "s",
  "me",
  "mi",
  "m" iacute,
  "m" iacute "a",
  "m" iacute "as",
  "m" iacute "o",
  "m" iacute "os",
  "mis",
  "mucho",
  "muchos",
  "muy",
  "nada",
  "ni",
  "no",
  "nos",
  "nosotras",
  "nosotros",
  "nuestra",
  "nuestras",
  "nuestro",
  "nuestros",
  "o",
  "os",
  "otra",
  "otras",
  "otro",
  "otros",
  "para",
  "pero",
  "poco",
  "por",
  "porque",
  "que",
  "qu" eacute,
  "quien",
  "quienes",
  "se",
  "sea",
  "se" aacute "is",
  "seamos",
  "sean",
  "seas",
  "ser",
  "ser" aacute,
  "ser" aacute "n",
  "ser" aacute "s",
  "ser" eacute,
  "ser" eacute "is",
  "seremos",
  "ser" iacute "a",
  "ser" iacute "ais",
  "ser" iacute "amos",
  "ser" iacute "an",
  "ser" iacute "as",
  "s" iacute,
  "sido",
  "siendo",
  "sin",
  "sobre",
  "sois",
  "somos",
  "son",
  "soy",
  "su",
  "sus",
  "suya",
  "suyas",
  "suyo",
  "suyos",
  "tambi" eacute "n",
  "tanto",
  "te",
  "tendr" aacute,
  "tendr" aacute "n",
  "tendr" aacute "s",
  "tendr" eacute,
  "tendr" eacute "is",
  "tendremos",
  "tendr" iacute "a",
  "tendr" iacute "ais",
  "tendr" iacute "amos",
  "tendr" iacute "an",
  "tendr" iacute "as",
  "tened",
  "ten" eacute "is",
  "tenemos",
  "tenga",
  "teng" aacute "is",
  "tengamos",
  "tengan",
  "tengas",
  "tengo",
  "ten" iacute "a",
  "ten" iacute "ais",
  "ten" iacute "amos",
  "ten" iacute "an",
  "ten" iacute "as",
  "tenida",
  "tenidas",
  "tenido",
  "tenidos",
  "teniendo",
  "ti",
  "tiene",
  "tienen",
  "tienes",
  "todo",
  "todos",
  "tu",
  "t?",
  "tus",
  "tuve",
  "tuviera",
  "tuvierais",
  "tuvi" eacute "ramos",
  "tuvieran",
  "tuvieras",
  "tuvieron",
  "tuviese",
  "tuvieseis",
  "tuvi" eacute "semos",
  "tuviesen",
  "tuvieses",
  "tuvimos",
  "tuviste",
  "tuvisteis",
  "tuvo",
  "tuya",
  "tuyas",
  "tuyo",
  "tuyos",
  "un",
  "una",
  "uno",
  "unos",
  "vosotras",
  "vosotros",
  "vuestra",
  "vuestras",
  "vuestro",
  "vuestros",
  "y",
  "ya",
  "yo",

  0
};

} // namespace zorba
/* vim:set et sw=2 ts=2: */
