import random

from hackgen import TestInputFormat, TestGenerator, Language


class Div64(TestInputFormat):
    def inputs(self, difficult_level: int) -> None:
        """
        deskripsi :
        Diberikan suatu bilangan X dengan jumlah digit maksimal adalah 4. Terdapat suatu bilangan
        spesial bernama Bilangan Pisi. Jika Y merupakan jumlah digit bilangan X maka, suatu
        bilangan dinyatakan sebagai Bilangan Pisi jika bilangan X bernilai sama dengan penjumlahan
        dari setiap digit bilangan X yang dipangkatkan Y.
        input :
        satu baris berisi satu bilangan x
        output :
        Satu baris berupa hasil pengecekan bilangan X merupakan Bilangan Pisi atau bukan. Jika X
        merupakan bilangan Pisi keluarkan “Pisi!”. Jika bukan bilangan pisi keluarkan “Nitnot!”.
        constraints :
        0 <= X <= 10^14
        0 <= Y <= 5
        """
        
        x = random.randint(0, 10**14)
        print(x)
        # y = random.randint(0, 5)
        
        


input_format = Div64()

test_generator = TestGenerator(
    10, input_format, Language.cpp('logic'), "Div64")
test_generator.run()