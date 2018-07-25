using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            Persona auxPersona = new Persona();
            int edad;
            string nombre;
            edad = int.Parse(Console.ReadLine());
            nombre = Console.ReadLine();
            //nombre = auxPersona.getNombre();
            Console.WriteLine("El nombre es " + nombre);
            Console.WriteLine("La edad es " + edad);
            Console.Read();
        }
    }
}
