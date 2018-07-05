using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Persona
    {
        private int edad;
        private string nombre;
        public Persona()
        {
            this.nombre = "";
            this.edad = 0;
        }
        public Persona(int edad, string nombre)
        {
            this.edad = edad;
            this.nombre = nombre;
        }
        public int setEdad(int edad)
        {
            this.edad = edad;
            return 0;
        }
        public int getEdad()
        {
            return this.edad;
        }
        public int setNombre(string nombre)
        {
            this.nombre = nombre;
            return 0;
        }
        public string getNombre()
        {
            return this.nombre;
        }
    }
}
