import java.util.*;



class brackets {
	public static void main(String []argh)
	{
		Scanner sc = new Scanner(System.in);
		Stack<Character> st = new Stack<>();
        
		while (sc.hasNext()) {
            while(!st.empty()){ st.pop();}
			String in = sc.next();
            for(char c : in.toCharArray()){
                if(st.empty()){
                    st.push(c);
                }else if(st.peek()=='(' && c==')'){
                    st.pop();
                }else if(st.peek()=='[' && c==']'){
                    st.pop();
                }else if(st.peek()=='{' && c=='}'){
                    st.pop();
                }else{
                    st.push(c);
                }
            }
            if(st.empty()){
                System.out.println("true");
            }else{
                System.out.println("false");
            }
		}
        sc.close();
	}
}
