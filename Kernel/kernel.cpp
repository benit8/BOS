/*
** BOS, 2020
** Kernel entry point
*/

#if defined(__linux__)
	#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
	#error "This kernel needs to be compiled with a ix86-elf compiler"
#endif

////////////////////////////////////////////////////////////////////////////////

#include "VGA.hpp"
#include "TTY.hpp"

////////////////////////////////////////////////////////////////////////////////

extern "C"
{

void kernel_main(void)
{
	TTY term;
	term.setColor(VGA::Color::White, VGA::Color::Red);
	term.write("Lorem ipsum dolor sit amet, consectetur adipisicing elit. Reiciendis ratione dicta maiores temporibus neque mollitia quisquam dolorem sunt totam obcaecati aut at quos harum, architecto veritatis perferendis ipsam laborum reprehenderit illum provident rerum id velit? Assumenda nulla ullam mollitia rem vero quod, ad pariatur sapiente impedit, quibusdam, aliquid enim natus. Tempore libero impedit voluptate id praesentium accusamus nemo placeat exercitationem, nisi alias necessitatibus perspiciatis ab et labore quam esse. Minima perspiciatis rem consequuntur nobis, recusandae ut. Sed quod quaerat atque labore recusandae quia nobis molestiae, sapiente quidem quam sit est laborum ipsa, autem officiis rem cupiditate illum magni? Architecto laboriosam eos tempora cupiditate, doloremque beatae non, veritatis illum illo perferendis alias, rem minima eius asperiores similique perspiciatis laborum natus? Voluptates voluptas aperiam, reiciendis quae quos soluta quam consequuntur velit. Vitae aliquam error unde fugiat. Maxime fugit perferendis soluta laboriosam provident deserunt illo dignissimos deleniti! Commodi quasi esse, qui tenetur nihil explicabo tempora magni dignissimos enim voluptatum voluptatem laborum earum. Fuga expedita sit laborum soluta, ab numquam possimus necessitatibus eum ullam totam officiis doloremque ad reiciendis molestiae culpa repellendus architecto veritatis iusto impedit eligendi. Odit dolore officia ad eius sunt aperiam laudantium sed ratione. Odit perspiciatis, architecto at aspernatur quis id.");
}

}
