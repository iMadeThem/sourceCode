import java.lang.ref.Reference;
import java.lang.ref.WeakReference;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;

public class WeakReferenceTest {
    public static void main(String[] args) throws InterruptedException
    {
        new WeakReferenceTest().doMain();
    }

    private void doMain() throws InterruptedException
    {
        while (true) {
            m();
        }
    }

    private List<Reference<Byte[]>> list = new ArrayList<Reference<Byte[]>>();
    private void m()
    {
        for (int i = 0; i < 10; i++) {
            Byte[] t = new Byte[10000];
            list.add(new WeakReference<Byte[]>(t));
        }
    }
}
