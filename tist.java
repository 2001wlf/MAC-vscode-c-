public calss Test{
	public static void main(String args[])
	{
		Dog d1=new Dog();
		String name="Jack",color="green";
		int age=20;
		d1.SetXxx(color,age,name);
		d1.GetXxx();
	}
}
class Dog{
	private string color,name;
	private int age;
	public Dog()
	{

	}
	public void SetXxx(String color,int age,String name)
	{
		this.age=age;
		this.name=name;
		this.color=color;
	}
	public void GetXxx()
	{
		System.out.println("color="+this.color);
		System.out.println("age="+this.age);
		System.out.println("name="+this.name);
	}
}